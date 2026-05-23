#include <iostream>
#include "Game.hpp"

int main()
{
     //Window
    std::cout << "Hello, SFML\n";
    Game game;

    // window/game loop
    while (game.getWindowIsOpen())
    {
        game.update();
        game.render();
    }

    // end application
    return 0;
}