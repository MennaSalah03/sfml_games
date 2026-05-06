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
    sf::Window window(sf::VideoMode(640, 480), "Shapes!", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;
    return 0;
}