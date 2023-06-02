#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "string"
class ScreenBase
{
protected:
	sf::Texture Texture;
	sf::Sprite Sprite;

public:
	ScreenBase() = default;
	
	~ScreenBase();

	void loader(std::string img_path);
	void draw_(sf::RenderWindow& window);
};

