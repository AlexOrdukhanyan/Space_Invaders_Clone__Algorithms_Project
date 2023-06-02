#include "Achievement.h"
#include <iostream>
int Achievement::num = 0;



Achievement::Achievement(std::string s1)
{
    loader(s1);
    Sprite.setTextureRect(sf::IntRect(5, 0, 200, 75));
    Sprite.scale(1.8f, 1.8f);
    Sprite.setPosition(sf::Vector2f(512, 75)); 

}

void Achievement::loader(std::string s1)
{
    if (!Texture.loadFromFile(s1)) {
        std::cout << "Unable to load texture";
        exit(-1);
    }
    Sprite.setTexture(Texture);
}


void Achievement::draw_(sf::RenderWindow & window) {
    Sprite.setPosition(sf::Vector2f(512, 0));
    window.draw(Sprite);
}

sf::Sprite Achievement::get_sprite()
{
    return Sprite;
}


