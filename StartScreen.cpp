#include "StartScreen.h"
StartScreen::StartScreen(std::string start_screen_immg_path) {
	loader(start_screen_immg_path);
	Sprite.setTextureRect(sf::IntRect(0, 0, 48, 8));
	Sprite.scale(6.f, 7.f);
	Sprite.setPosition(sf::Vector2f(120, 220));
}