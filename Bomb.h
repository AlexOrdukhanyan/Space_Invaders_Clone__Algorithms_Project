#pragma once
#include "BaseProjectile.h"
class Bomb : public BaseProjectile
{
public:
	int enerhy = 1;

	int projectile_speed = 0;
	static int num_of_bombs;
	static int Timer;
private:
	//static int num_of_bombs;
public:
	
	Bomb(std::string img_path);
	~Bomb();

	void static_animation(std::pair<int, bool>& timer);
	void movement(float elapsed);
	
	friend class Collision;

};

