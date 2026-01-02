#include "Level.hpp"

Level::Level()
{
    // Ground
    sf::RectangleShape ground;
    ground.setSize({1200.f, 60.f});
    ground.setPosition({40.f, 640.f});
    ground.setFillColor(sf::Color(80, 80, 80));
    solids.push_back(ground);

    // A few platforms in a line (simple linear map)
    for (int i = 0; i < 4; i++)
    {
        sf::RectangleShape plat;
        plat.setSize({220.f, 30.f});
        plat.setPosition({120.f + i * 260.f, 520.f - i * 40.f});
        plat.setFillColor(sf::Color(90, 90, 90));
        solids.push_back(plat);
    }

    // A wall at the far right (to test collision)
    sf::RectangleShape wall;
    wall.setSize({40.f, 520.f});
    wall.setPosition({1240.f, 120.f});
    wall.setFillColor(sf::Color(70, 70, 70));
    solids.push_back(wall);
}

void Level::draw(sf::RenderTarget& target) const
{
    for (const auto& s : solids)
        target.draw(s);
}

bool Level::collides(const sf::FloatRect& rect) const
{
    for (const auto& s : solids)
    {
        if (s.getGlobalBounds().findIntersection(rect).has_value())
            return true;
    }
    return false;
}