#include "Collision.h"

void Collision::check_collision_enemy_projectile( std::vector<BaseProjectile>& projectiles, std::vector<BaseEnemy>& enemies)
{
	if (!enemies.empty() && !projectiles.empty()) {
		for (int i = 0; i < projectiles.size(); ++i) {
			for (int j = 0; j < enemies.size(); ++j) {
				if (projectiles[i].get_sprite().getGlobalBounds().intersects(enemies[j].get_sprite().getGlobalBounds())) {
					projectiles.erase(projectiles.begin() + i);
					enemies.erase(enemies.begin() + j);
					static Player player;
					player.score++;
					break;
				}
			}
		}
	}
}

void Collision::check_collision_enemy_projectile2(std::vector<Projectile2>& projectiles2, std::vector<BaseEnemy>& enemies)
{
	if (!enemies.empty() && !projectiles2.empty()) {
		for (int i = 0; i < projectiles2.size(); ++i) {
			for (int j = 0; j < enemies.size(); ++j) {
				if (projectiles2[i].get_sprite().getGlobalBounds().intersects(enemies[j].get_sprite().getGlobalBounds())) {
					projectiles2[i].energy--;
					if (projectiles2[i].energy <= 0) {
						projectiles2.erase(projectiles2.begin() + i);
					}
					enemies.erase(enemies.begin() + j);
					static Player player;
					player.score++;
					break;
				}
			}
		}
	}
}

void Collision::check_collision_enemy2_projectile2(std::vector<Projectile2>& projectiles2, std::vector<Enemy2>& enemies2)
{
	if (!enemies2.empty() && !projectiles2.empty()) {
		for (int i = 0; i < projectiles2.size(); ++i) {
			for (int j = 0; j < enemies2.size(); ++j) {
				if (projectiles2[i].get_sprite().getGlobalBounds().intersects(enemies2[j].get_sprite().getGlobalBounds())) {
					projectiles2[i].energy--;
					if (projectiles2[i].energy <= 0) {
						projectiles2.erase(projectiles2.begin() + i);
					}
					enemies2.erase(enemies2.begin() + j);
					static Player player;
					player.score++;
					break;
				}
			}
		}
	}

}




void Collision::check_collision_enemy2_projectile(std::vector<BaseProjectile>& projectiles, std::vector<Enemy2>& enemies2)
{
	if (!enemies2.empty() && !projectiles.empty()) {
		for (int i = 0; i < projectiles.size(); ++i) {
			for (int j = 0; j < enemies2.size(); ++j) {
				if (projectiles[i].get_sprite().getGlobalBounds().intersects(enemies2[j].get_sprite().getGlobalBounds())) {
					projectiles.erase(projectiles.begin() + i);
					enemies2.erase(enemies2.begin() + j);
					static Player player;
					player.score++;
					break;
				}
			}
		}
	}
}

void Collision::check_collision_bomb_enemy(std::vector<Bomb>& bombs, std::vector<BaseEnemy>& enemies)
{
	if (!enemies.empty() && !bombs.empty()) {
		for (int i = 0; i < bombs.size(); ++i) {
			for (int j = 0; j < enemies.size(); ++j) {
				if (bombs[i].get_sprite().getGlobalBounds().intersects(enemies[j].get_sprite().getGlobalBounds())) {
					bombs[i].num_of_bombs--;
					bombs.erase(bombs.begin() + i);
					enemies.erase(enemies.begin() + j);
					static Player player;
					player.score++;
					break;
				}
			}
		}
	}
}

void Collision::check_collision_bomb_enemy2(std::vector<Bomb>& bombs, std::vector<Enemy2>& enemies2)
{
	if (!enemies2.empty() && !bombs.empty()) {
		for (int i = 0; i < bombs.size(); ++i) {
			for (int j = 0; j < enemies2.size(); ++j) {
				if (bombs[i].get_sprite().getGlobalBounds().intersects(enemies2[j].get_sprite().getGlobalBounds())) {
					bombs[i].num_of_bombs--;
					bombs.erase(bombs.begin() + i);
					enemies2.erase(enemies2.begin() + j);
					static Player player;
					player.score++;
					break;
				}
			}
		}
	}

}


void Collision::check_collision_player_coll(Player& player, std::vector<Collectable>& collectables)
{
	if (!collectables.empty()) {
		for (int i = 0; i < collectables.size(); ++i) {
			if (collectables[i].get_sprite().getGlobalBounds().intersects(player.get_sprite().getGlobalBounds())) {
				collectables.erase(collectables.begin() + i);
				//player.points_increment();
				player.points++;
				break;
			}
		}
	}
}

void Collision::check_player_enemies(Player& player, std::vector<BaseEnemy>& enemies, std::vector<Enemy2>& enemies2, int& gameControl)
{
	check_collision_player_enemy(player, enemies);
	check_collision_player_enemy2(player, enemies2);
	if (player.health <= 0) {
		gameControl = 2;
	}
}



void Collision::check_collision_player_enemy(Player& player, std::vector<BaseEnemy>& enemies)
{
	if (!enemies.empty()) {
		for (int i = 0; i < enemies.size(); ++i) {
			if (enemies[i].get_sprite().getGlobalBounds().intersects(player.get_sprite().getGlobalBounds())) {
				enemies.erase(enemies.begin() + i);
				//player.health_decrease_by_one();
				player.health--;
				break;
			}
		}
	}
}

void Collision::check_collision_player_enemy2(Player& player, std::vector<Enemy2>& enemies2)
{
	if (!enemies2.empty()) {
		for (int i = 0; i < enemies2.size(); ++i) {
			if (enemies2[i].get_sprite().getGlobalBounds().intersects(player.get_sprite().getGlobalBounds())) {
				enemies2.erase(enemies2.begin() + i);
				//player.health_decrease_by_two();
			    player.health -= 2;
				break;
			}
		}
	}
}
