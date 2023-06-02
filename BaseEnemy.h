#pragma once



#include "Player.h"
#include "ObjectBase.h"
class BaseEnemy : public ObjectBase
{
protected:
	/*sf::Texture EnemyTexture;
	sf::Sprite EnemySprite;*/
	int enemy_speed = 200;
public:
	static int Timer;

public:
	BaseEnemy() = default;
	BaseEnemy(std::string Enemypath);
	~BaseEnemy();

	void movement(float elapsed);


	void static_animation(std::pair<int, bool>& timer);
	friend class Collision;
};

