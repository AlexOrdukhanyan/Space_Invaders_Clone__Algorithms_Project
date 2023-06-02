#pragma once
#include "Player.h"
#include "ObjectBase.h"
class BaseProjectile : public ObjectBase
{
public:
	static int Timer;
protected:
	int projectile_speed = 600;
	/*sf::Texture ProjectileTexture;
	sf::Sprite ProjectileSprite;*/

public:
	BaseProjectile() = default;
	BaseProjectile(std::string projectile_img_path);
	~BaseProjectile();

	virtual void movement(float elapsed);
	virtual void static_animation(std::pair<int, bool>& timer);
	void change_position(float x, float y);

	


	friend class Collision;
};

