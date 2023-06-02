#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class BackGround
{
private:
	sf::Texture BackGroundTexture;
	sf::Sprite BackGroundSprite;

	sf::Texture LineTexture;
	sf::Sprite LineSprite;
public:
	BackGround(std::string background_img_path, std::string line_img);
	~BackGround();

	sf::Sprite get_sprite();
	sf::Texture get_texture();

	//void change_to_game_over(std::string game_over_img_path);
	void draw_(sf::RenderWindow& window);
	void draw_line(sf::RenderWindow& window);
};

