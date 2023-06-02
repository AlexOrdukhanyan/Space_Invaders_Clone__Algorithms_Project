#include "BaseEnemy.h"
int BaseEnemy::Timer = 0;
BaseEnemy::BaseEnemy(std::string Enemypath)
{
    loader(Enemypath);
    Sprite.setTextureRect(sf::IntRect(0, 0, 16, 13));
    Sprite.scale(1.8f, 1.8f);
}


BaseEnemy::~BaseEnemy()
{
 
}


void BaseEnemy::movement(float elapsed)
{
   Sprite.move(0, enemy_speed * elapsed / 1000);
}



void BaseEnemy::static_animation(std::pair<int, bool>& timer)
{
   
    
    if (timer.first < 64 && timer.second == true) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(0, 0, 16, 12));
        }
        else if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(16, 0, 16, 12));
        }
        else if (timer.first < 48 && timer.first >= 32) {
            Sprite.setTextureRect(sf::IntRect(32, 0, 16, 12));
        }
        else if (timer.first < 64 && timer.first >= 48) {
            Sprite.setTextureRect(sf::IntRect(48, 0, 16, 12));
        }
        ++timer.first;
    }
    if (timer.first == 64) {
        timer.second = false;
        timer.first--;
    }
    else if (timer.first < 64 && timer.second == false) {
        if (timer.first < 16) {
            Sprite.setTextureRect(sf::IntRect(48, 0, 16, 12));
        }
        else if (timer.first < 32 && timer.first >= 16) {
            Sprite.setTextureRect(sf::IntRect(32, 0, 16, 12));
        }
        else if (timer.first < 48 && timer.first >= 32) {
            Sprite.setTextureRect(sf::IntRect(16, 0, 16, 12));
        }
        else if (timer.first < 64 && timer.first >= 48) {
            Sprite.setTextureRect(sf::IntRect(0, 0, 16, 12));
        }
        --timer.first;
    }
    if (timer.first == 0 && timer.second == false) {
        timer.second = true;
        timer.first++;
    }
    


}







