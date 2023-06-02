#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectBase.h"
#include <string>
#include <iostream>
class Collectable : public ObjectBase
{
	
	int collectable_speed = 200;
public:
	static int Timer;
//private:
//	sf::Texture CollectableTexture;
//	sf::Sprite CollectableSprite;
public:

	Collectable(std::string collectable_img_path);
	~Collectable();

	void movement(float elapsed);
	void static_animation(std::pair<int, bool>& timer);
	//void set_position_rand(sf::RenderWindow& window);

	friend class Collision;
};

