#pragma once
#include "BaseProjectile.h"
class Projectile2 : public BaseProjectile
{
public:
	int energy = 2;
	static int Timer;
private:
	int projectile2_speed = 400;

public:

	Projectile2(std::string projectile2_img_path);
	~Projectile2();

	void static_animation(std::pair<int, bool>& timer);
	void movement(float elapsed);
	//void draw_(sf::RenderWindow& window);
	friend class Collision;

};

