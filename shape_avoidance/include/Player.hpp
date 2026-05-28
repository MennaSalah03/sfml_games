#ifndef PLAYER_H
    #define PLAYER_H

#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
    sf::CircleShape * player;
public:
    Player();
    virtual ~Player();
    void initPlayer();
    void renderPlayer(sf::RenderTarget* target);
    void updatePlayer(sf::Vector2i newPlayerPos);
    void limitPlayerMotion(sf::Vector2f windowSize);
    void increasePlayerSize();
    void decreasePlayersize();
    void adjustPlayerWithPointer();
};

#endif
