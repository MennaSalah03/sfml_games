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
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Shapes!", sf::Style::Titlebar | sf::Style::Close);
}


void Game::initEnemies()
{
    //this->enemy.setPosition();
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineThickness(1.f);
    this->enemy.setOutlineColor(sf::Color::White);
}
// game constructor
Game::Game()
{
    this->initvars();
    this->initwindow();
    this->initEnemies();
    this->window->setFramerateLimit(144);
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
        this->enemy.setPosition(
                    mousePosWindowView.x - this->enemy.getSize().x / 2,
                    mousePosWindowView.y - this->enemy.getSize().y / 2
                    );
    }
}

/* Where the game's at positions, and stuff
*/
void Game::update()
{
    this->pollEvents();
    this->updateMousPos();
    std::cout << mousePosWindowView.x << " " << mousePosWindowView.y << "\n"; 
}

void Game::updateMousPos()
{
    /** Update the mouse position relative to game window.
    * Return: void
    */
   if (sf::Mouse::getPosition(*this->window).x >= 0 && sf::Mouse::getPosition(*this->window).y >= 0)
   {
    this->mousePosWindowView = sf::Mouse::getPosition(*this->window);
   }
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

    this->window->clear();
    // draw game
    this->window->draw(this->enemy);
    this->window->display();
}