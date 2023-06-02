#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class Achievement
{
private:
	sf::Sprite Sprite;
	sf::Texture Texture;
	void loader(std::string s1);
	
	
public:
	static int num;
    int Timer;
	Achievement(std::string s1);
	void draw_(sf::RenderWindow& window);
	sf::Sprite get_sprite();

};

