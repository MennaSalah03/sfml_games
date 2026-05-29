#include <iostream>
#include "Player.hpp"

// player constructor
Player::Player()
{
    this->player = new sf::CircleShape();
    this->initPlayer();
}

// Player Deconstructor
Player::~Player()
{
    delete this->player;
    this->player = nullptr;
}

void Player::initPlayer()
{
    this->player->setPosition(750, 300);
    this->player->setRadius(25.f);
    this->player->setOrigin(this->player->getRadius(), this->player->getRadius());
    this->player->setFillColor(sf::Color(255, 214, 232));
}

void Player::limitPlayerMotion(sf::Vector2f windowSize)
{
    /** limitPlayerMotion
     * Limits where the player can go. It can't go beyond the window limits.
     * Updates the position to the limits of the window if it tries going beyond it.
     * windowSize: the size of the window
     * retuns: void
     */
    float edgeX = this->player->getPosition().x;
    float edgeY = this->player->getPosition().y;
    float radius = this->player->getRadius();

    if (edgeX - radius < 0.f) edgeX = radius;
    else if (edgeX + radius > windowSize.x) edgeX = windowSize.x - radius;

    if (edgeY - radius < 0.f) edgeY = radius;
    else if (edgeY + radius > windowSize.y) edgeY = windowSize.y - radius;

    this->player->setPosition(edgeX, edgeY);
}

void Player::increasePlayerSize()
{
    float newRadius = this->player->getRadius() + 5.0;
    this->player->setRadius(newRadius);
    this->player->setOrigin(newRadius, newRadius);
}

void Player::decreasePlayersize()
{
    float newRadius = this->player->getRadius() - 5.0;
    // minimum possible decrease is 5    
    if (newRadius < 5.0) newRadius = 5.0;
    this->player->setRadius(newRadius);
    this->player->setOrigin(newRadius, newRadius);


}

void Player::updatePlayer(sf::Vector2i newPlayerPos)
{
    this->player->setPosition(static_cast<sf::Vector2f> (newPlayerPos));
}

void Player::renderPlayer(sf::RenderTarget* target)
{
    target->draw(*player);
}