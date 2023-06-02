#include "Bomb.h"
int Bomb::num_of_bombs = 0;
int Bomb::Timer = 0;
Bomb::Bomb(std::string img_path)
{
    
	loader(img_path);
	Sprite.setTextureRect(sf::IntRect(0, 2, 16, 16));
	Sprite.scale(4.f, 4.f);
   // num_of_bombs++;
}

Bomb::~Bomb()
{
   // num_of_bombs--;
}

void Bomb::static_animation(std::pair<int, bool>& timer)
{
    if (timer.first < 32 && timer.second == true) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(4, 5, 7, 16));
        }
        else if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(20, 5, 7, 16));
        }
        ++timer.first;
    }
    if (timer.first == 32) {
        timer.second = false;
        timer.first--;
    }
    else if (timer.first < 32 && timer.second == false) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(20, 5, 7, 16));
        }
        else if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(4, 5, 7, 16));
        }
        --timer.first;
    }
    if (timer.first == 0 && timer.second == false) {
        timer.second = true;
        timer.first++;
    }
}

void Bomb::movement(float elapsed)
{
    projectile_speed = 0;
}
