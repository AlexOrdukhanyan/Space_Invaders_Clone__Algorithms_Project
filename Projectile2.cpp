#include "Projectile2.h"
#include <SFML/Graphics.hpp>
int Projectile2::Timer = 0;
Projectile2::Projectile2(std::string projectile2_img_path)
{
    loader(projectile2_img_path);
    Sprite.setTextureRect(sf::IntRect(0, 2, 16, 16));
    Sprite.scale(1.8f, 1.8f);
   // Sprite.setPosition(sf::Vector2f(280, 450));
}

Projectile2::~Projectile2()
{

}

void Projectile2::static_animation(std::pair<int, bool>& timer) {

    if (timer.first < 128 && timer.second == true) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        }
        else if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
        }
        else if (timer.first < 48 && timer.first >= 32) {
            Sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));
        }
        else if (timer.first < 64 && timer.first >= 48) {
            Sprite.setTextureRect(sf::IntRect(48, 0, 16, 16));
        }
        else if (timer.first < 80 && timer.first >= 64) {
            Sprite.setTextureRect(sf::IntRect(64, 0, 16, 16));
        }
        else if (timer.first < 96 && timer.first >= 80) {
            Sprite.setTextureRect(sf::IntRect(80, 0, 16, 16));
        }
        else if (timer.first < 112 && timer.first >= 96) {
            Sprite.setTextureRect(sf::IntRect(96, 0, 16, 16));
        }
        else if (timer.first < 128 && timer.first >= 112) {
            Sprite.setTextureRect(sf::IntRect(112, 0, 16, 16));
        }
        ++timer.first;
    }
    if (timer.first == 128) {
        timer.second = false;
        timer.first--;
    }
    else if (timer.first < 128 && timer.second == false) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(112, 0, 16, 16));
        }
        else if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(96, 0, 16, 16));
        }
        else if (timer.first < 48 && timer.first >= 32) {
            Sprite.setTextureRect(sf::IntRect(80, 0, 16, 16));
        }
        else if (timer.first < 64 && timer.first >= 48) {
            Sprite.setTextureRect(sf::IntRect(64, 0, 16, 16));
        }
        else if (timer.first < 80 && timer.first >= 64) {
            Sprite.setTextureRect(sf::IntRect(48, 0, 16, 16));
        }
        else if (timer.first < 96 && timer.first >= 80) {
            Sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));
        }
        else if (timer.first < 112 && timer.first >= 96) {
            Sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
        }
        else if (timer.first < 128 && timer.first >= 112) {
            Sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        }

        --timer.first;
    }
    if (timer.first == 0 && timer.second == false) {
        timer.second = true;
        timer.first++;
    }



}

void Projectile2::movement(float elapsed)
{
    Sprite.move(0.f, -projectile2_speed * elapsed / 1000);
}



