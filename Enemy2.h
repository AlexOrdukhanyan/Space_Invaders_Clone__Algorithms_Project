#pragma once
#include "BaseEnemy.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
class Enemy2 : public BaseEnemy
{
private:
    //std::vector<int> speeds_x;
    int enemy2_speed = 150;
public:
    static int Timer;
public:
    Enemy2(std::string Enemypath);

    void movement(float elapsed, sf::Vector2u& window_size);
    void set_rand_speed_x();

};

