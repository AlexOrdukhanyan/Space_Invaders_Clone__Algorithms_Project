#include "BaseProjectile.h"

int BaseProjectile::Timer = 0;

BaseProjectile::BaseProjectile(std::string projectile_img_path)
{
    loader(projectile_img_path);
    Sprite.setTextureRect(sf::IntRect(0, 2, 16, 16));
    Sprite.scale(1.8f, 1.8f);
   // ProjectileSprite.setPosition(sf::Vector2f(280, 450));
}
BaseProjectile::~BaseProjectile()
{
}


void BaseProjectile::movement(float elapsed)
{
    Sprite.move(0.f,  - projectile_speed * elapsed / 1000);
}


void BaseProjectile::static_animation(std::pair<int, bool>& timer)
{
    //static int i = 0;
    //static bool anim = true;
    if (timer.first < 32 && timer.second == true) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(0, 2, 16, 16));
        }
        else if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(16, 2, 16, 16));
        }
        ++timer.first;
    }
    if (timer.first == 32) {
        timer.second = false;
        timer.first--;
    }
    else if (timer.first < 32 && timer.second == false) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(16, 2, 16, 16));
        }
        else if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(0, 2, 16, 16));
        }
        --timer.first;
    }
    if (timer.first == 0 && timer.second == false) {
        timer.second = true;
        timer.first++;
    }
}



void BaseProjectile::change_position(float x, float y)
{
    Sprite.setPosition(x, y);
}





