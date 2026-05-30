#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>

using namespace sf;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int width = 20;
    const int height = 20;
    const float cell = 20.f;
    const int max_length = 100; // Увеличил лимит

    RenderWindow window(VideoMode({ (unsigned int)(width * cell), (unsigned int)(height * cell) }), "Solid Snake");
    window.setFramerateLimit(60);

    int snake_x[max_length];
    int snake_y[max_length];
    int length = 1;

    snake_x[0] = width / 2;
    snake_y[0] = height / 2;

    int apple_x, apple_y;
    int dx = 0, dy = -1;
    int next_dx = 0, next_dy = -1; // Для плавного управления

    auto SpawnApple = [&]() {
        bool onSnake;
        do {
            onSnake = false;
            apple_x = rand() % (width - 2) + 1;
            apple_y = rand() % (height - 2) + 1;
            for (int i = 0; i < length; i++) {
                if (snake_x[i] == apple_x && snake_y[i] == apple_y) onSnake = true;
            }
        } while (onSnake);
        };

    SpawnApple();

    bool gameOver = false;
    float timer = 0.f;
    float delay = 0.15f;
    Clock clock;
    RectangleShape block(Vector2f(cell - 1.f, cell - 1.f));

    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        timer += time;

        while (const std::optional event = window.pollEvent()) {
            if (event->is<Event::Closed>()) window.close();

            // Управление через события (нажатие клавиш)
            if (const auto* keyPressed = event->getIf<Event::KeyPressed>()) {
                if (keyPressed->code == Keyboard::Key::W && dy != 1) { next_dx = 0; next_dy = -1; }
                if (keyPressed->code == Keyboard::Key::S && dy != -1) { next_dx = 0; next_dy = 1; }
                if (keyPressed->code == Keyboard::Key::A && dx != 1) { next_dx = -1; next_dy = 0; }
                if (keyPressed->code == Keyboard::Key::D && dx != -1) { next_dx = 1; next_dy = 0; }
            }
        }

        if (gameOver) continue; // Можно добавить экран рестарта

        // Логика движения по таймеру
        if (timer > delay) {
            timer = 0;
            dx = next_dx;
            dy = next_dy;

            // Двигаем хвост
            for (int i = length - 1; i > 0; i--) {
                snake_x[i] = snake_x[i - 1];
                snake_y[i] = snake_y[i - 1];
            }

            // Двигаем голову
            snake_x[0] += dx;
            snake_y[0] += dy;

            // Проверка столкновения со стенами
            if (snake_x[0] <= 0 || snake_x[0] >= width - 1 || snake_y[0] <= 0 || snake_y[0] >= height - 1)
                gameOver = true;

            // Самопересечение
            for (int i = 1; i < length; i++) {
                if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i]) gameOver = true;
            }

            // Поедание яблока
            if (snake_x[0] == apple_x && snake_y[0] == apple_y) {
                if (length < max_length) length++;
                SpawnApple();
            }
        }

        // Отрисовка
        window.clear(Color::Black);

        // Стены
        block.setFillColor(Color(100, 100, 100));
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                    block.setPosition({ i * cell, j * cell });
                    window.draw(block);
                }
            }
        }

        // Яблоко
        block.setFillColor(Color::Red);
        block.setPosition({ apple_x * cell, apple_y * cell });
        window.draw(block);

        // Змейка
        for (int i = 0; i < length; i++) {
            block.setFillColor(i == 0 ? Color::Yellow : Color::Green);
            block.setPosition({ snake_x[i] * cell, snake_y[i] * cell });
            window.draw(block);
        }

        window.display();
    }

    return 0;
}
