#include "BackGround.h"

BackGround::BackGround(std::string background_img_path, std::string line_img)
{
	if (!BackGroundTexture.loadFromFile(background_img_path)) {
		std::cout << " Unable to load texture";
	}
	if (!LineTexture.loadFromFile(line_img)) {
		std::cout << " Unable to load txture";
	}
	BackGroundSprite.setTexture(BackGroundTexture);
	BackGroundSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	BackGroundSprite.scale(8.f, 8.f);
	BackGroundSprite.setPosition(sf::Vector2f(0, 0));
	LineSprite.setTexture(LineTexture);
	LineSprite.setTextureRect(sf::IntRect(0, 0, 1, 512));
	LineSprite.setPosition(sf::Vector2f(512, 0));
}

BackGround::~BackGround()
{
}

sf::Sprite BackGround::get_sprite()
{
	return this->BackGroundSprite;
}

sf::Texture BackGround::get_texture()
{
	return this->BackGroundTexture;
}

//void BackGround::change_to_game_over(std::string game_over_img_path)
//{
//	if (!BackGroundTexture.loadFromFile(game_over_img_path)) {
//		std::cout << " Unable to load texture";
//	}
//	BackGroundSprite.setTexture(BackGroundTexture);
//	BackGroundSprite.setTextureRect(sf::IntRect(0, 0, 72, 8));
//	BackGroundSprite.scale(3.f, 3.f);
//	BackGroundSprite.setPosition(sf::Vector2f(0, 0));
//}



void BackGround::draw_(sf::RenderWindow& window)
{
	window.draw(BackGroundSprite);
}

void BackGround::draw_line(sf::RenderWindow& window)
{
	window.draw(LineSprite);
}
