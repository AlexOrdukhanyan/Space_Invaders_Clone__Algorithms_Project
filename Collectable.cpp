#include "Collectable.h"

int Collectable::Timer = 0;

Collectable::Collectable(std::string collectable_img_path)
{
    loader(collectable_img_path);
	Sprite.setTextureRect(sf::IntRect(0, 0, 16, 12));
	Sprite.scale(2.f, 2.f);
	//CollectableSprite.setPosition(sf::Vector2f(50, 0));
}

Collectable::~Collectable()
{
}

void Collectable::movement(float elapsed)
{
	Sprite.move(0, collectable_speed * elapsed / 1000);
}

void Collectable::static_animation(std::pair<int, bool>& timer)
{
    if (timer.first < 48 && timer.second == true) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(0, 0, 16, 12));
        }
        if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(16, 0, 16, 12));
        }
        if (timer.first < 48 && timer.first >= 32) {
            Sprite.setTextureRect(sf::IntRect(32, 0, 16, 12));
        }
        ++timer.first;
    }
    if (timer.first == 48) {
        timer.second = false;
        timer.first--;
    }
    if (timer.first < 48 && timer.second == false) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(32, 0, 16, 12));
        }
        if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(16, 0, 16, 12));
        }
        if (timer.first < 48 && timer.first >= 32) {
            Sprite.setTextureRect(sf::IntRect(0, 0, 16, 12));
        }
        --timer.first;
    }
    if (timer.first == 0 && timer.second == false) {
        timer.second = true;
        timer.first++;
    }
}
