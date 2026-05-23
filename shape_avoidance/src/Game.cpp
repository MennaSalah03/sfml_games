#include <iostream>
#include "Game.hpp"

// private functions
void Game::initvars()
{
    this->window = nullptr;
}

void Game::initwindow()
{
    this->video_mode.height = 600;
    this->video_mode.width = 800;
    //this->video_mode.getDesktopMode;
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Avoidant square", sf::Style::Titlebar | sf::Style::Close); 
}

// game constructor
Game::Game()
{
    this->initvars();
    this->initwindow();
    this->window->setFramerateLimit(60);
}
// game destructor
Game::~Game()
{
    delete this->window;
}

// accessors
const bool Game::getWindowIsOpen() const
{
    return this->window->isOpen();
}

// Functions (update game logic)
void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                    break;
                }
        }
    }
}

/* Where the game's at positions, and stuff
*/
void Game::update()
{
    this->pollEvents();
    this->player->updatePlayer(sf::Mouse::getPosition());
}


/* Game visuals updates
* 1. clears old frame
* 2. render objects
* 3. displays frame in window
*
* Return: void
*/
void Game::render()
{
    this->window->clear(sf::Color(54,69,79));
    // draw game
    this->player->renderPlayer(this->window);
    this->window->display();
}