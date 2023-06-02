#pragma once
#include "BaseEnemy.h"
#include "Enemy2.h"
#include "BaseProjectile.h"
#include "Projectile2.h"
#include "Collectable.h"
#include "Player.h"
#include "Bomb.h"
#include <vector>
class Collision
{
public:
	void check_collision_enemy_projectile(std::vector<BaseProjectile>& projectiles, std::vector<BaseEnemy>& enemies);

	void check_collision_enemy_projectile2(std::vector<Projectile2>& projectiles2, std::vector<BaseEnemy>& enemies);

	void check_collision_enemy2_projectile2(std::vector<Projectile2>& projectiles2, std::vector<Enemy2>& enemies2);

	void check_collision_enemy2_projectile(std::vector<BaseProjectile>& projectiles, std::vector<Enemy2>& enemies2);

	void check_collision_player_coll(Player& player, std::vector<Collectable>& colllectables);

	void check_player_enemies(Player& player, std::vector<BaseEnemy>& enemies, std::vector<Enemy2>& enemies2, int& gameControl);
	
	void check_collision_bomb_enemy(std::vector<Bomb>& bombs, std::vector<BaseEnemy>& enemies);

	void check_collision_bomb_enemy2(std::vector<Bomb>& bombs, std::vector<Enemy2>& enemies2);
private:

	void check_collision_player_enemy(Player& player, std::vector<BaseEnemy>& enemies);

	void check_collision_player_enemy2(Player& player, std::vector<Enemy2>& enemies2);
	friend class Player;
};

