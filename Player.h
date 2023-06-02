#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "BaseProjectile.h"
#include <vector>
class Player
{
private:
	sf::Texture PlayerTexture;
	sf::Sprite PlayerShip;
	
	sf::Texture BoosterTexture;
	sf::Sprite BoosterSprite;
	int ship_speed = 300;

	

public:

	static int health;
	static int points;
	static int score;
	static int penalty;
	//int x, y;

public:
	Player() = default;
	Player(std::string img_dir1, std::string img_dir2);
	void destroy_obj();
	~Player();
	
	void draw_(sf::RenderWindow& window);
	void movement(float elapsed);
	void check_borders(sf::RenderWindow& window);
	void chech_health();


	void booster_animation();
	sf::Sprite& get_sprite();
	sf::Texture& get_texture();


	/*void health_decrease_by_one();
	void health_decrease_by_two();
	void score_increment();
	void points_increment();*/

	friend class Collision;	
};

