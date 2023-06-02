#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
class ObjectBase
{
public:
	
protected:

	sf::Texture Texture;
	sf::Sprite Sprite;

public:
	ObjectBase() = default;

	
	virtual ~ObjectBase();

	void loader(std::string img_path);
	virtual void movement(float elapsed) = 0; 
	virtual void static_animation(std::pair<int, bool>& timer) = 0; 
	void set_position_rand(sf::RenderWindow& window);
	sf::Sprite get_sprite();
	sf::Texture get_texture();

	void draw_(sf::RenderWindow& window);
};

