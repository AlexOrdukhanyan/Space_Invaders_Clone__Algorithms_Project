#include "Headers.h"

int main()
{
    srand(time(NULL));
    
    // initializing the window
    sf::RenderWindow window(sf::VideoMode(512 + 300, 512), "Space Invaders Clone", sf::Style::Close | sf::Style::Resize);
    sf::Vector2u window_size = window.getSize();
    window.setFramerateLimit(60);
   
    // vectors for objects
    projectiles_v projectiles;
    projectiles2_v projectiles2;
    enemies_v enemies;
    enemies2_v enemies2;
    collectables_v collectables;
    un_map all_timers;
    bombs_v bombs;

 
    objects_v objects;

    sf::Clock clock;

    // initializing objects
    Player player(player_img_path, booster_img_path);
    BaseEnemy enemy1(enemy_img_path);
    Enemy2 enemy2(enemy2_img_path);
    BaseProjectile projectile1(projectile_img_path);
    Projectile2 projectile2(projectile2_img_path);
    BackGround background(background_img_path, line_img_path);
    StartScreen start_screen(start_screen_img_path);
    GameOverScreen g_o_screen(game_over_img_path);
    Collectable collectable1(collectable_img_path);
    Collision collision;
    Bomb bomb1(bomb_img_path);

    Achievements ach_s;


    while (window.isOpen())
    {
        
        sf::Event event;
   
        while (window.pollEvent(event))
        {
            // checking the window
            if (event.type == sf::Event::Closed ||
                event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape ) {
               
                window.close();

            }
        }
        float elapsed = float(clock.restart().asMilliseconds());

        if (gameControl == 0) {
            // start screen
            window.clear(sf::Color(0, 0, 18, 0));
            start_screen.draw_(window);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
                gameControl = 1;
            }
        }
        else  if (gameControl == 1) {
            // the main game part
            activate_animation(projectiles, projectiles2, enemies, enemies2, collectables, bombs, all_timers);

            spawner_projectiles(player, projectile1, projectiles, all_timers);
            spawner_projectiles2(player, projectile2, projectiles2, all_timers);
            spawner_enemies(enemy1, enemies, all_timers, window);
            spawner_enemies2(enemy2, enemies2, all_timers, window);
            spawner_collectables(collectable1, collectables, all_timers, window);
            spawner_bombs(player, bomb1, bombs, all_timers, window);

            activate_movement(player, elapsed, projectiles, projectiles2, enemies, enemies2, collectables, window_size, all_timers);
            player.check_borders(window);

            collision_check(player, collision, projectiles, projectiles2, enemies, enemies2, collectables, bombs, gameControl);
            window.clear(sf::Color(0, 0, 18, 0));

            ach(ach_s, player, window);
            draw_main(player, window, projectiles, projectiles2, enemies, enemies2, collectables, bombs, background);

        }
        else if (gameControl == 2) {
            // after the game is over
            window.clear(sf::Color(0, 0, 18, 0));
            g_o_screen.draw_(window);
        }
        background.draw_line(window);
        window.display();

    }

    return 0;
}