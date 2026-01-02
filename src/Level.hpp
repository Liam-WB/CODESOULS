#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Level
{
public:
    Level();

    void draw(sf::RenderTarget& target) const;
    bool collides(const sf::FloatRect& rect) const;

private:
    std::vector<sf::RectangleShape> solids; // platforms/walls
};