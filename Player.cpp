#include "Player.h"

int Player::health = 10;
int Player::points = 0;
int Player::score = 0;
int Player::penalty = 0;
Player::Player(std::string img_dir1, std::string img_dir2) {

    if (!PlayerTexture.loadFromFile(img_dir1)) {
        std::cout << "Unable to load texture";
        exit(-1);
    }
    PlayerShip.setTexture(PlayerTexture);
    PlayerShip.setTextureRect(sf::IntRect(16, 0, 16, 16));
    PlayerShip.scale(1.8f, 1.8f);
    PlayerShip.setPosition(sf::Vector2f(280, 465)); //280 400

    if (!BoosterTexture.loadFromFile(img_dir2)) {
        std::cout << "Unable to load booster texture";
        exit(-1);
    }
    BoosterSprite.setTexture(BoosterTexture);
    BoosterSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    BoosterSprite.scale(1.8f, 1.8f);
    BoosterSprite.setPosition(sf::Vector2f(280, 492));
}

void Player::destroy_obj()
{
    
    /*delete &player.PlayerShip;
    delete &player.PlayerTexture;
    delete &player.BoosterSprite;
    delete &player.BoosterTexture;*/
   
}

Player::~Player()
{
    destroy_obj();
    //destroy_obj(*this);
}

void Player::draw_(sf::RenderWindow& window) {
    if (this != nullptr) {
        window.draw(PlayerShip);
        window.draw(BoosterSprite);
    }

    
   
}

void Player::movement(float elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        PlayerShip.move(ship_speed * elapsed / 1000, 0);
        PlayerShip.setTextureRect(sf::IntRect(32, 0, 16, 16));
        BoosterSprite.move(ship_speed * elapsed / 1000, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        PlayerShip.move(-ship_speed * elapsed / 1000, 0);
        PlayerShip.setTextureRect(sf::IntRect(0, 0, 16, 16));
        BoosterSprite.move(-ship_speed * elapsed / 1000, 0);
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        PlayerShip.setTextureRect(sf::IntRect(16, 0, 16, 16));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        PlayerShip.setTextureRect(sf::IntRect(16, 0, 16, 16));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)) {
       
        PlayerShip.setPosition(PlayerShip.getPosition().x, 470);
        BoosterSprite.setPosition(BoosterSprite.getPosition().x, 497);
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)) {
        PlayerShip.setPosition(PlayerShip.getPosition().x, 465);
        BoosterSprite.setPosition(BoosterSprite.getPosition().x, 492);
       /* PlayerShip.setPosition(PlayerShip.getPosition().x, ship_speed * elapsed / 1000);
        BoosterSprite.setPosition(BoosterSprite.getPosition().x, ship_speed * elapsed / 1000);*/
    }
    booster_animation();
    booster_animation();

    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        PlayerShip.move(0, -ship_speed * elapsed / 1100);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        PlayerShip.move(0, ship_speed * elapsed / 1100);
    }*/
}

void Player::check_borders(sf::RenderWindow& window) {
    sf::Vector2u size = window.getSize();
    if (PlayerShip.getPosition().y > size.y - 32) {
        PlayerShip.setPosition(sf::Vector2f(PlayerShip.getPosition().x, size.y - 32));
        BoosterSprite.setPosition(sf::Vector2f(BoosterSprite.getPosition().x, size.y));
    }
    if (PlayerShip.getPosition().y < -1) {
        PlayerShip.setPosition(sf::Vector2f(PlayerShip.getPosition().x, -1));
    }
    if (PlayerShip.getPosition().x > size.x - 30 - 300) {
        PlayerShip.setPosition(sf::Vector2f(size.x - 30 - 300, PlayerShip.getPosition().y));
        BoosterSprite.setPosition(sf::Vector2f(size.x - 30 - 300, BoosterSprite.getPosition().y));
    }
    if (PlayerShip.getPosition().x < -1) {
        PlayerShip.setPosition(sf::Vector2f(-1, PlayerShip.getPosition().y));
        BoosterSprite.setPosition(sf::Vector2f(-1, BoosterSprite.getPosition().y));
    }
}

void Player::chech_health()
{
    if (health <= 0) {
        Player::~Player();
    }
}

void Player::booster_animation()
{
    static int i = 0;
    static bool anim = true;
    if (i < 32 && anim == true) {
        if (i < 16) {
            BoosterSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        }
        else if (i < 32 && i >= 16) {
            BoosterSprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
        }
        ++i;
    }
    if (i == 32) {
        anim = false;
        i--;
    }
    else if (i < 32 && anim == false) {
        if (i < 16) {
            BoosterSprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
        }
        else  if (i < 32 && i >= 16) {
            BoosterSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        }
        --i;
    }
    if (i == 0 && anim == false) {
        anim = true;
        i++;
    }

}

sf::Sprite& Player::get_sprite()
{
    return PlayerShip;
}

sf::Texture& Player::get_texture()
{
    return PlayerTexture;
}

//void Player::health_decrease_by_one()
//{
//    health--;
//}
//
//void Player::health_decrease_by_two()
//{
//    health -= 2;
//}
//
//void Player::points_increment()
//{
//    points++;
//}
//
//void Player::score_increment()
//{
//    score++;
//}


