#include "ObjectBase.h"



ObjectBase::~ObjectBase()
{
}

void ObjectBase::loader(std::string img_path)
{
    if (!Texture.loadFromFile(img_path)) {
        std::cout << "Unable to load texture";
        exit(-1);
    }
    Sprite.setTexture(Texture);
   /* Sprite.setTextureRect(sf::IntRect(0, 2, 16, 16));
    Sprite.scale(1.8f, 1.8f);*/
}

void ObjectBase::set_position_rand(sf::RenderWindow& window)
{
    Sprite.setPosition((rand() % int(window.getSize().x - Sprite.getScale().x - 40 - 300)), -115);
}

sf::Sprite ObjectBase::get_sprite()
{
	return Sprite;
}

sf::Texture ObjectBase::get_texture()
{
	return Texture;
}

void ObjectBase::draw_(sf::RenderWindow& window)
{
    window.draw(Sprite);
}
