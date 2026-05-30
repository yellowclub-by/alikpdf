//#include <SFML/Graphics.hpp>
//#include <optional>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//using namespace sf;
//struct Point {
//	int x;
//	int y;
//};
//constexpr unsigned GAME_whidth = 500;
//constexpr unsigned GAME_hight = 1000;
//constexpr float Doodle_hidth = 50.f;
//constexpr float Doodle_whidth = 70.f;
//constexpr float Platform_hidth = 68.f;
//constexpr float Platform_whidth = 14.f;
//constexpr int Platform_count = 10;
//
//void FirstSprite(Sprite& sprite, float targetWidth, float targetHigth) {
//	const Vector2u texSize = sprite.getTexture().getSize();
//	sprite.setScale({ targetWidth / static_cast<float>(texSize.x),targetHigth / static_cast<float>(texSize.y) });
//}
//int name() {
//
//	srand(static_cast<unsigned>(time(nullptr)));
//	RenderWindow app(VideoMode({ GAME_whidth,GAME_hight }), "Doodle Jump");
//	Texture tBackground;
//	Texture tPlatform;
//	Texture tDoodle;
//	if (!tBackground.loadFromFile("Images\dackground.jpg")) {
//		return-1;
//	};
//	if (!tPlatform.loadFromFile("Images/doodle.png")) {
//		return-1;
//	};
//	if (!tDoodle.loadFromFile("Images/platform.png")) {
//		return-1;
//	};
//	Sprite sBackground(tBackground);
//	Sprite sPlatform(tPlatform);
//	Sprite sDoodle(tDoodle);
//	FirstSprite(sBackground, static_cast<float>(GAME_whidth), static_cast<float>(GAME_hight));
//	FirstSprite(sPlatform, (Platform_whidth), (Platform_hidth));
//	FirstSprite(sBackground, (Doodle_whidth), (Doodle_hidth));
//	Point platform[20];
//	for (int i = 0; i < Platform_count; i++) {
//		platform[i].x = rand() % GAME_whidth;
//		platform[i].y = rand() % GAME_hight;
//	}
//	int x = 100;
//	int y = 100;
//	int h = 200;
//	float dy = 0;
//
//}