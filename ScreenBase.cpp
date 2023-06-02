#include "ScreenBase.h"

ScreenBase::~ScreenBase()
{
}

void ScreenBase::loader(std::string img_path)
{
	if (!Texture.loadFromFile(img_path)) {
		std::cout << " Unable to load texture";
	}
	Sprite.setTexture(Texture);
	/*G_O_Sprite.setTextureRect(sf::IntRect(0, 0, 72, 8));
	G_O_Sprite.scale(6.f, 7.f);
	G_O_Sprite.setPosition(sf::Vector2f(37, 220));*/
}

void ScreenBase::draw_(sf::RenderWindow& window)
{
	window.draw(Sprite);
}
