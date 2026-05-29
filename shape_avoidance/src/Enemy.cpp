#include <iostream>
#include "Enemy.hpp"

// player constructor
Enemy::Enemy()
{
    this->enemy = new sf::RectangleShape();
    this->initEnemy();
}
// Player Deconstructor
Enemy::~Enemy()
{
    delete this->enemy;
    this->enemy = nullptr;
}

void Enemy::initEnemy()
{
    this->enemy->setPosition(750, 300);
    this->enemy->setSize(sf::Vector2f(25.f, 25.f));
    this->enemy->setOrigin(this->enemy->getSize().x, this->enemy->getSize().y);
    this->enemy->setFillColor(sf::Color(255, 241, 182));
}


void Enemy::increaseEnemySize()
{
    float newHeight = this->enemy->getSize().x + 5.0;
    float newWidth = this->enemy->getSize().y + 5.0;
    this->enemy->setSize(sf::Vector2f(newHeight, newWidth));
}

void Enemy::decreaseEnemySize()
{
    float newHeight = this->enemy->getSize().x - 5.0;
    float newWidth = this->enemy->getSize().y - 5.0;
    this->enemy->setSize(sf::Vector2f(newHeight, newWidth));
}

void Enemy::updateEnemy(sf::Vector2f newEnemyPos)
{
    this->enemy->setPosition(newEnemyPos);
}

void Enemy::renderEnemy(sf::RenderTarget* target)
{
    target->draw(*enemy);
}