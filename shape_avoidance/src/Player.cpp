#include <iostream>
#include "Player.hpp"

// player constructor
Player::Player()
{
    this->initPlayer();
}

// Player Deconstructor
Player::~Player()
{
    //delete this->player;
}

void Player::initPlayer()
{
    this->player.setPosition(750, 300);
    this->player.setRadius(50.f);
    this->player.setFillColor(sf::Color::Magenta);
}


void Player::updatePlayer(sf::Vector2i newPlayerPos)
{
    this->player.setPosition(static_cast<sf::Vector2f> (newPlayerPos));
}

void Player::renderPlayer(sf::RenderTarget* target)
{
    target->draw(this->player);
}