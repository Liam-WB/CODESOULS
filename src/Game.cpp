#include "Game.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode({1280, 720}), "CodeSouls")
{
    window.setVerticalSyncEnabled(true);

    // Load a font (put a .ttf in assets/fonts/)
    if (!font.openFromFile("assets/fonts/Montserrat-Regular.ttf"))
    {
        std::cerr << "Failed to load font. Put a .ttf in assets/fonts/.\n";
    }

    titleText.setFont(font);
    titleText.setString("CodeSouls");
    titleText.setCharacterSize(64);
    titleText.setPosition({64.f, 64.f});

    hintText.setFont(font);
    hintText.setString("Press Enter to Start\nPress Esc to Quit");
    hintText.setCharacterSize(24);
    hintText.setPosition({64.f, 160.f});
}

void Game::run()
{
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

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

        // Key presses (only on press, not held)
        if (event->is<sf::Event::KeyPressed>())
        {
            const auto& key = event->getIf<sf::Event::KeyPressed>()->code;

            if (key == sf::Keyboard::Key::Escape)
                window.close();

            if (state == State::Menu && key == sf::Keyboard::Key::Enter)
                state = State::Playing;
        }
    }
}

void Game::update(float dt)
{
    if (state == State::Menu) updateMenu(dt);
    else updatePlaying(dt);
}

void Game::updateMenu(float)
{
    // Optional: animate menu text (blink, bob, etc.)
}

void Game::updatePlaying(float dt)
{
    player.update(dt, level); // we’ll pass the map for collisions
}

void Game::render()
{
    window.clear(sf::Color::Black);

    if (state == State::Menu) renderMenu();
    else renderPlaying();

    window.display();
}

void Game::renderMenu()
{
    window.draw(titleText);
    window.draw(hintText);
}

void Game::renderPlaying()
{
    level.draw(window);
    player.draw(window);
}