#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

// private functions
void Game::initvars()
{
    this->window = nullptr;
}

void Game::initwindow()
{
    this->video_mode.height = 600;
    this->video_mode.width = 800;
    this->window = new sf::RenderWindow (
            sf::VideoMode(this->video_mode.width, this->video_mode.height),
            "Avoidant square",
            sf::Style::Titlebar | sf::Style::Close
        ); 
}

// game constructor
Game::Game()
{
    this->initvars();
    this->initwindow();
    this->window->setFramerateLimit(60);
    this->player = new Player();
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
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                    player->increasePlayerSize();
                else if (event.mouseButton.button == sf::Mouse::Right)
                    player->decreasePlayersize();
        }
    }
}

/* Where the game's at positions, and stuff
*/
void Game::update()
{
    this->pollEvents();
    player->updatePlayer(sf::Mouse::getPosition(*this->window));
    player->limitPlayerMotion(static_cast<sf::Vector2f> (this->window->getSize()));

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
    this->window->clear(sf::Color(43, 45, 66));
    // draw game
    this->player->renderPlayer(this->window);
    this->window->display();
}