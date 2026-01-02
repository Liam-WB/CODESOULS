#include "Game.hpp"

Game::Game()
    : window(sf::VideoMode({1280, 720}), "CodeSouls")
{
    window.setVerticalSyncEnabled(true); // smoother than framerate limit
}

void Game::run()
{
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds(); // delta time in seconds

        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update(float dt)
{
    player.update(dt);
}

void Game::render()
{
    window.clear(sf::Color::Black);
    player.draw(window);
    window.display();
}