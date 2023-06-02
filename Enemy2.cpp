#include "Enemy2.h"

int Enemy2::Timer = 0;

Enemy2::Enemy2(std::string Enemypath)
{
    loader(Enemypath);
    Sprite.setTextureRect(sf::IntRect(0, 0, 16, 13));
    Sprite.scale(1.8f, 1.8f);
    set_rand_speed_x();
}

void Enemy2::movement(float elapsed, sf::Vector2u& window_size)
{
   
   // enemy2_speed = set_rand_speed_x();

    if (Sprite.getPosition().x >= window_size.x - 20 - 300 || Sprite.getPosition().x < 0) {
        enemy2_speed *= -1;
    }
   
    Sprite.move(enemy2_speed * elapsed / 500, enemy_speed * elapsed / 1000);


}
void Enemy2::set_rand_speed_x() {

    int num = rand() & 1;
    if (num == 1) {
        enemy2_speed = 150;
    }
    if (num == 0) {
        enemy2_speed -150;
    }
}


