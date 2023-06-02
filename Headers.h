#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Achievement.h"
#include "Achievements.h"
#include "Animation.h"
#include "Player.h"
#include "BaseEnemy.h"
#include "Enemy2.h"
#include "BaseProjectile.h"
#include "Projectile2.h"
#include "Bomb.h"
#include "BackGround.h"
#include "ScreenBase.h"
#include "StartScreen.h"
#include "GameOverScreen.h"
#include "Collectable.h"
#include "Collision.h"
#include <unordered_map>


std::string player_img_path = "images/Player_ship (16 x 16).png";
std::string enemy_img_path = "images/Lips (16 x 16).png";
std::string enemy2_img_path = "images/Alan (16 x 16).png";
std::string projectile_img_path = "images/Player_charged_beam (16 x 16).png";
std::string projectile2_img_path = "images/Player_charged_square_shot (16 x 16).png";
std::string booster_img_path = "images/Boosters (16 x 16).png";
std::string missle_img_path = "images/Player_missile_shots (16 x 16).png";
std::string background_img_path = "images/Space_BG (2 frames) (64 x 64).png";
std::string collectable_img_path = "images/Power_item (16 x 16).png";
std::string game_over_img_path = "images/GAME_OVER (72 x 8).png";
std::string start_screen_img_path = "images/START (48 x 8).png";
std::string bomb_img_path = "images/Enemy_projectile (16 x 16).png";
std::string line_img_path = "images/Line (1 x 512 ).png";





int gameControl = 0;

using un_map = std::unordered_map<std::string, std::vector<std::pair<int, bool>>>;
using enemies_v = std::vector<BaseEnemy>;
using enemies2_v = std::vector<Enemy2>;
using projectiles_v = std::vector<BaseProjectile>;
using projectiles2_v = std::vector<Projectile2>;
using objects_v = std::vector<ObjectBase>;
using collectables_v = std::vector<Collectable>;
using bombs_v = std::vector<Bomb>;




// calls all functions collisions

void collision_check(Player& player, Collision& collision, projectiles_v& projectiles, projectiles2_v& projectiles2, enemies_v& enemies, enemies2_v& enemies2, collectables_v& collectables, bombs_v& bombs, int& gameControl) {

    collision.check_collision_enemy_projectile(projectiles, enemies);
    collision.check_collision_enemy2_projectile(projectiles, enemies2);
    collision.check_collision_enemy_projectile2(projectiles2, enemies);
    collision.check_collision_enemy2_projectile2(projectiles2, enemies2);

    collision.check_collision_player_coll(player, collectables);
    collision.check_player_enemies(player, enemies, enemies2, gameControl);

    collision.check_collision_bomb_enemy(bombs, enemies);
    collision.check_collision_bomb_enemy2(bombs, enemies2);

}

// starting from here functions for object spawns
void spawner_projectiles(Player& player, BaseProjectile& projectile1, projectiles_v& projectiles, un_map& all_timers) {
    if (projectile1.Timer < 7) {
        projectile1.Timer++;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J) && projectile1.Timer >= 7) {
        projectile1.change_position(player.get_sprite().getPosition().x + player.get_sprite().getScale().x / 2, player.get_sprite().getPosition().y + player.get_sprite().getScale().y / 2);

        projectiles.push_back(BaseProjectile(projectile1));
        all_timers["projectile"].push_back({ 0, true });
        projectile1.Timer = 0;
    }
}

void spawner_projectiles2(Player& player, Projectile2& projectile2, projectiles2_v& projectiles2, un_map& all_timers) {
    if (projectile2.Timer < 15) {
        projectile2.Timer++;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K) && projectile2.Timer >= 15 && player.points >= 5) {
        projectile2.change_position(player.get_sprite().getPosition().x + player.get_sprite().getScale().x / 2, player.get_sprite().getPosition().y + player.get_sprite().getScale().y / 2);

        projectiles2.push_back(Projectile2(projectile2));
        all_timers["projectile2"].push_back({ 0, true });
        projectile2.Timer = 0;
    }
}

void spawner_bombs(Player& player, Bomb& bomb1, bombs_v& bombs, un_map& all_timers, sf::RenderWindow& window) {
    if (bomb1.Timer < 25) {
        bomb1.Timer++;
    }
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L) && bomb1.Timer >= 25 && player.points >= 2 && bomb1.num_of_bombs <= 3) {
        bomb1.change_position(player.get_sprite().getPosition().x + player.get_sprite().getScale().x / 2, player.get_sprite().getPosition().y + player.get_sprite().getScale().y / 2);
       
        bombs.push_back(Bomb(bomb1));
        all_timers["bomb"].push_back({ 0, true });
        bomb1.num_of_bombs++;
        bomb1.Timer = 0;
    }
}


void spawner_enemies(BaseEnemy& enemy1, enemies_v& enemies, un_map& all_timers, sf::RenderWindow& window) {
    if (enemy1.Timer < 40) {
        enemy1.Timer++;
    }
    if (enemy1.Timer >= 40) {
        enemy1.set_position_rand(window);
        enemies.push_back(BaseEnemy(enemy1));
        all_timers["enemy"].push_back({ 0, true });

        enemy1.Timer = 0;
    }
}

void spawner_enemies2(Enemy2& enemy2, enemies2_v& enemies2, un_map& all_timers, sf::RenderWindow& window) {
    if (enemy2.Timer < 150) {
        enemy2.Timer++;
    }
    if (enemy2.Timer >= 150) {
        enemy2.set_position_rand(window);
        enemies2.push_back(Enemy2(enemy2));
        all_timers["enemy2"].push_back({ 0, true });
      

        enemy2.Timer = 0;
    }
}

void spawner_collectables(Collectable& collectable1, collectables_v& collectables, un_map& all_timers, sf::RenderWindow& window) {
    if (collectable1.Timer < 500) {
        collectable1.Timer++;
    }
    if (collectable1.Timer >= 500) {
        collectable1.set_position_rand(window);
        collectables.push_back(Collectable(collectable1));
        all_timers["collectable"].push_back({ 0, true });

        collectable1.Timer = 0;
    }
}
// end of spawners




// main function for character movement
void activate_movement(Player& player, float elapsed, projectiles_v& projectiles, projectiles2_v& projectiles2, enemies_v& enemies, enemies2_v& enemies2, collectables_v& collectables, sf::Vector2u& window_size, un_map& all_timers) {
   
    
    player.movement(elapsed);

    
    for (int i = 0; i < enemies.size(); ++i) {
        enemies[i].movement(elapsed);
        if (enemies[i].get_sprite().getPosition().y > window_size.y) {
            enemies.erase(enemies.begin() + i);
            all_timers["enemy"].erase(all_timers["enemy"].begin() + i);
            player.penalty++;
        }
    }
    for (int i = 0; i < projectiles.size(); ++i) {
        projectiles[i].movement( elapsed);
        if (projectiles[i].get_sprite().getPosition().y < 0) {
            projectiles.erase(projectiles.begin() + i);
            all_timers["projectile"].erase(all_timers["projectile"].begin() + i);
        }
    }
    for (int i = 0; i < projectiles2.size(); ++i) {
        projectiles2[i].movement(elapsed);
        if (projectiles2[i].get_sprite().getPosition().y < 0) {
            projectiles2.erase(projectiles2.begin() + i);
            all_timers["projectile2"].erase(all_timers["projectile2"].begin() + i);
        }
    }
    for (int i = 0; i < collectables.size(); ++i) {
        collectables[i].movement(elapsed);
        if (collectables[i].get_sprite().getPosition().y > window_size.y) {
            collectables.erase(collectables.begin() + i);
            all_timers["collectable"].erase(all_timers["collectable"].begin() + i);
        }
    }
    for (int i = 0; i < enemies2.size(); ++i) {
        enemies2[i].movement(elapsed, window_size);
        if (enemies2[i].get_sprite().getPosition().y > window_size.y) {
            enemies2.erase(enemies2.begin() + i);
            all_timers["enemy2"].erase(all_timers["enemy2"].begin() + i);
            player.penalty++;
        }
    }

}

// is responsible for objects' static animation
void activate_animation(projectiles_v& projectiles, projectiles2_v& projectiles2, enemies_v& enemies, enemies2_v& enemies2, collectables_v& collectables, bombs_v& bombs, un_map& all_timers) {

    for (int i = 0; i < projectiles.size(); ++i) {
        projectiles[i].static_animation(all_timers["projectile"][i]);
    }
    for (int i = 0; i < projectiles2.size(); ++i) {
        projectiles2[i].static_animation(all_timers["projectile2"][i]);
        projectiles2[i].static_animation(all_timers["projectile2"][i]);
        projectiles2[i].static_animation(all_timers["projectile2"][i]);
        projectiles2[i].static_animation(all_timers["projectile2"][i]);
    }
    for (int i = 0; i < enemies.size(); ++i) {
        enemies[i].static_animation(all_timers["enemy"][i]);
    }
    for (int i = 0; i < collectables.size(); ++i) {
        collectables[i].static_animation(all_timers["collectable"][i]);
    }
    for (int i = 0; i < enemies2.size(); ++i) {
        enemies2[i].static_animation(all_timers["enemy2"][i]);
        enemies2[i].static_animation(all_timers["enemy2"][i]);

    }
    for (int i = 0; i < bombs.size(); ++i) {
        bombs[i].static_animation(all_timers["bomb"][i]);
    }

}

// draws everything
void draw_main(Player& player, sf::RenderWindow& window, projectiles_v& projectiles, projectiles2_v& projectiles2, enemies_v& enemies, enemies2_v& enemies2, collectables_v& collectables, bombs_v& bombs, BackGround& background) {
   
    background.draw_(window);
    player.draw_(window);


  /*  for (int i = 0; i < objects.size(); ++i) {
        objects[i].draw - (window);
    }*/
    for (int i = 0; i < enemies.size(); ++i) {
        enemies[i].draw_(window);
    }
    for (int i = 0; i < projectiles.size(); ++i) {
        projectiles[i].draw_(window);
    }
    for (int i = 0; i < projectiles2.size(); ++i) {
        projectiles2[i].draw_(window);
    }
    for (int i = 0; i < collectables.size(); ++i) {
        collectables[i].draw_(window);
    }
    for (int i = 0; i < enemies2.size(); ++i) {
        enemies2[i].draw_(window);
    }
    for (int i = 0; i < bombs.size(); ++i) {
        bombs[i].draw_(window);
    }
}


// initializing the achievemnt system
void ach(Achievements& achievements, Player& player, sf::RenderWindow& window) {
    achievements.check(player, window);
}
