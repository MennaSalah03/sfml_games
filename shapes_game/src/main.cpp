#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

int main()
{
     //Window
    std::cout << "Hello, SFML\n";
    sf::RenderWindow game_window(sf::VideoMode(800, 600), "Shapes!", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    // window/game loop
    while (game_window.isOpen())
    {
        // Event polling
        while (game_window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    game_window.close();
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        game_window.close();
                    }
                    
            }
        }

        // Update

        // Render
        game_window.clear(sf::Color(0, 0, 255, 255)); //clear the old frame

        // draw game
        game_window.display(); // tell app that window is done drawing
    }

    // end application
    return 0;
}