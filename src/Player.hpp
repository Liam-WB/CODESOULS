#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();
    void update(float dt);
    void draw(sf::RenderTarget& target) const;

private:
    void handleMovement(float dt);

    sf::RectangleShape body;
    sf::Vector2f velocity{0.f, 0.f};

    float speed = 300.f; // pixels per second
};