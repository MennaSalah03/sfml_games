
#ifndef GAME_H
    #define GAME_H
#endif

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
    //windows
    sf::RenderWindow *window; // pointer to window
    sf::VideoMode video_mode;
    sf::Event event;

    //Game objects
    sf::RectangleShape enemy;

    // private functions
    void initvars();
    void initwindow();
    void initEnemies();

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