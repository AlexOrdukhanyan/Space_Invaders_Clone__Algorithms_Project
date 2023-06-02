#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(std::string game_over_img_path) {
	loader(game_over_img_path);
	Sprite.setTextureRect(sf::IntRect(0, 0, 72, 8));
	Sprite.scale(6.f, 7.f);
	Sprite.setPosition(sf::Vector2f(37, 220));

}

GameOverScreen::~GameOverScreen()
{
}



