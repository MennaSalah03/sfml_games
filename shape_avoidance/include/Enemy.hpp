#ifndef ENEMY_H
    #define ENEMY_H

#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Enemy
{
private:
    sf::RectangleShape *enemy;
public:
    // constructors
    Enemy();
    virtual ~Enemy();

    // initialize method
    void initEnemy();
    void increaseEnemySize();
    void decreaseEnemySize();
    void updateEnemy(sf::Vector2f newEnemyPos);
    void renderEnemy(sf::RenderTarget* target);
};

#endif
