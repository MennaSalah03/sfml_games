#pragma once

#ifndef GAME_H
    #define GAME_H
#endif

/* 
* Class that acts as the game engine
* Wrapper class for all the functionalities.
*/

class Game
{
private:
    // private functions
    void initars();
    void initwindow();

public:
    Game();
    //constructors
    virtual ~Game();

    // Functions
    void update();
    void render();

};