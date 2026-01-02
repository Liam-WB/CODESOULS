#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Level.hpp"

class Game
{
public:
    Game();
    void run();

private:
    enum class State { Menu, Playing };

    void processEvents();
    void update(float dt);
    void render();

    void updateMenu(float dt);
    void updatePlaying(float dt);

    void renderMenu();
    void renderPlaying();

    sf::RenderWindow window;
    sf::Clock clock;

    State state = State::Menu;

    // Menu UI
    sf::Font font;
    sf::Text titleText;
    sf::Text hintText;

    // Gameplay
    Player player;
    Level level;
};