#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdint>

// Константы
const unsigned int WIN_W = 1024;
const unsigned int WIN_H = 768;
const float PI = 3.14159265f;

// Структура пешехода
struct Pedestrian {
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Color color;
    bool isAlive = true;
};

// Структура здания
struct Building {
    sf::FloatRect bounds;
    sf::Color color;
};

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Окно
    sf::RenderWindow window(sf::VideoMode({ WIN_W, WIN_H }), "GTA: San Andreas - SFML 3 Edition");
    window.setFramerateLimit(60);

    // Камера (Вид сверху)
    sf::View view(sf::Vector2f{ 2000.f, 2000.f }, sf::Vector2f{ static_cast<float>(WIN_W), static_cast<float>(WIN_H) });

    // Игрок (Машина)
    sf::RectangleShape player(sf::Vector2f{ 40.f, 20.f });
    player.setOrigin(sf::Vector2f{ 20.f, 10.f });
    player.setFillColor(sf::Color::Red);
    player.setPosition(sf::Vector2f{ 2000.f, 2000.f });

    float speed = 0.f;
    float maxSpeed = 8.f;
    float acceleration = 0.2f;
    float braking = 0.3f;
    float friction = 0.05f;
    float angle = 0.f;
    float turnSpeed = 3.0f;

    // Статистика
    int score = 0;
    int respect = 0;
    bool missionActive = true;

    // Генерация карты
    std::vector<Building> worldBuildings;
    std::vector<sf::Vector2f> roadNodes;

    for (float x = 0; x < 4000; x += 400) {
        for (float y = 0; y < 4000; y += 400) {
            roadNodes.push_back(sf::Vector2f{ x + 350.f, y + 350.f });

            if ((std::abs(x - 2000.f) < 1.f && std::abs(y - 2000.f) < 1.f) ||
                (std::abs(x - 2400.f) < 1.f && std::abs(y - 1600.f) < 1.f)) continue;

            Building b;
            b.bounds = sf::FloatRect({ x + 50.f, y + 50.f }, { 300.f, 300.f });
            b.color = sf::Color(static_cast<std::uint8_t>(50 + std::rand() % 50),
                static_cast<std::uint8_t>(50 + std::rand() % 50),
                static_cast<std::uint8_t>(50 + std::rand() % 50));
            worldBuildings.push_back(b);
        }
    }

    sf::Vector2f missionTarget = roadNodes[std::rand() % roadNodes.size()];

    // Спавн пешеходов
    std::vector<Pedestrian> peds;
    for (int i = 0; i < 100; ++i) {
        Pedestrian p;
        p.position = roadNodes[std::rand() % roadNodes.size()] + sf::Vector2f{ static_cast<float>((std::rand() % 40) - 20), static_cast<float>((std::rand() % 40) - 20) };
        p.velocity = sf::Vector2f{ static_cast<float>((std::rand() % 3) - 1), static_cast<float>((std::rand() % 3) - 1) };
        p.color = (std::rand() % 2 == 0) ? sf::Color::Green : sf::Color(128, 0, 128);
        peds.push_back(p);
    }

    sf::Font font;
    bool fontLoaded = font.openFromFile("C:/Windows/Fonts/Arial.ttf");

    sf::Text uiText(font);
    uiText.setCharacterSize(20);
    uiText.setFillColor(sf::Color::White);

    // Главный цикл
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Управление
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            if (speed < maxSpeed) speed += acceleration;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            if (speed > -maxSpeed / 2) speed -= braking;
        }
        else {
            if (speed > 0) speed -= friction;
            if (speed < 0) speed += friction;
            if (std::abs(speed) < friction) speed = 0.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && std::abs(speed) > 0.5f) {
            angle -= turnSpeed * (speed > 0 ? 1.f : -1.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && std::abs(speed) > 0.5f) {
            angle += turnSpeed * (speed > 0 ? 1.f : -1.f);
        }

        // Движение
        player.setRotation(sf::degrees(angle));
        float rad = angle * PI / 180.f;

        // Раздельное движение по осям для идеальной коллизии
        sf::Vector2f pos = player.getPosition();

        // 1. Движение по X
        pos.x += std::cos(rad) * speed;
        player.setPosition(pos);

        sf::FloatRect playerBounds = player.getGlobalBounds();
        for (const auto& b : worldBuildings) {
            if (auto intersection = playerBounds.findIntersection(b.bounds)) {
                // Выталкиваем по оси X
                if (std::cos(rad) * speed > 0) {
                    pos.x -= intersection->size.x;
                }
                else {
                    pos.x += intersection->size.x;
                }
                player.setPosition(pos);
                speed = -speed * 0.2f; // Легкий отскок
                break;
            }
        }

        // 2. Движение по Y
        pos = player.getPosition();
        pos.y += std::sin(rad) * speed;
        player.setPosition(pos);

        playerBounds = player.getGlobalBounds();
        for (const auto& b : worldBuildings) {
            if (auto intersection = playerBounds.findIntersection(b.bounds)) {
                // Выталкиваем по оси Y
                if (std::sin(rad) * speed > 0) {
                    pos.y -= intersection->size.y;
                }
                else {
                    pos.y += intersection->size.y;
                }
                player.setPosition(pos);
                speed = -speed * 0.2f; // Легкий отскок
                break;
            }
        }

        // Обновление пешеходов
        for (auto& p : peds) {
            if (!p.isAlive) continue;

            p.position += p.velocity;

            sf::FloatRect pedRect(p.position - sf::Vector2f{ 4.f, 4.f }, { 8.f, 8.f });
            for (const auto& b : worldBuildings) {
                if (pedRect.findIntersection(b.bounds).has_value()) {
                    p.position -= p.velocity;
                    p.velocity = -p.velocity;
                    break;
                }
            }

            if (std::rand() % 200 == 0) {
                p.velocity = sf::Vector2f{ static_cast<float>((std::rand() % 3) - 1), static_cast<float>((std::rand() % 3) - 1) };
            }

            if (player.getGlobalBounds().findIntersection(pedRect).has_value()) {
                p.isAlive = false;
                if (p.color == sf::Color::Green) {
                    score -= 100;
                    respect -= 5;
                }
                else {
                    score += 200;
                    respect += 10;
                }
            }
        }

        // Проверка миссии
        if (missionActive) {
            sf::FloatRect targetRect(missionTarget - sf::Vector2f{ 40.f, 40.f }, { 80.f, 80.f });
            if (player.getGlobalBounds().findIntersection(targetRect).has_value()) {
                missionActive = false;
                score += 5000;
                respect += 50;
            }
        }

        // Камера
        view.setCenter(player.getPosition());

        // Рендеринг
        window.clear(sf::Color(45, 45, 45));
        window.setView(view);

        for (const auto& b : worldBuildings) {
            sf::RectangleShape rect(b.bounds.size);
            rect.setPosition(b.bounds.position);
            rect.setFillColor(b.color);
            rect.setOutlineThickness(4.f);
            rect.setOutlineColor(sf::Color(20, 20, 20));
            window.draw(rect);
        }

        if (missionActive) {
            sf::CircleShape marker(25.f);
            marker.setOrigin(sf::Vector2f{ 25.f, 25.f });
            marker.setPosition(missionTarget);
            marker.setFillColor(sf::Color(255, 255, 0, 180));
            window.draw(marker);
        }

        for (const auto& p : peds) {
            if (!p.isAlive) continue;
            sf::CircleShape pedShape(6.f);
            pedShape.setOrigin(sf::Vector2f{ 6.f, 6.f });
            pedShape.setPosition(p.position);
            pedShape.setFillColor(p.color);
            window.draw(pedShape);
        }

        window.draw(player);

        // UI
        window.setView(window.getDefaultView());
        if (fontLoaded) {
            std::string uiStr = "Money: $" + std::to_string(score) +
                "\nRespect: " + std::to_string(respect) +
                (missionActive ? "\n\nMISSION: Drive to the YELLOW marker on the street!" : "\n\nMISSION PASSED! RESPECT+");
            uiText.setString(uiStr);
            uiText.setPosition(sf::Vector2f{ 20.f, 20.f });
            window.draw(uiText);
        }

        window.display();
    }

    return 0;
}
