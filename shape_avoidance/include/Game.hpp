#ifndef GAME_H
    #define GAME_H

#include "Player.hpp"
#include "Enemy.hpp"

#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>


/* 
* Class that acts as the game engine
* Wrapper class for all the functionalities.
*/

class Game
{
private:
    //variables
    //window
    sf::RenderWindow *window; // pointer to window
    sf::VideoMode video_mode;
    sf::Event event;

    Player* player;
    std::vector<Enemy> *enemy;
    
    void initvars();
    void initwindow();
    int maxEnemies = 10;
public:
    // con/destructors
    Game();
    virtual ~Game();


    // Accessors
    const bool getWindowIsOpen() const;

    // Functions
    void pollEvents();
    void update();
    void render();

};

#endif
