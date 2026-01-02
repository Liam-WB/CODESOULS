#include "Player.hpp"

Player::Player()
{
    body.setSize({48.f, 48.f});
    body.setOrigin(body.getSize() / 2.f);
    body.setPosition({640.f, 360.f});
    body.setFillColor(sf::Color::White);
}

void Player::update(float dt)
{
    handleMovement(dt);
    body.move(velocity * dt);
}

void Player::handleMovement(float dt)
{
    (void)dt; // dt not needed here, but kept for consistency

    velocity = {0.f, 0.f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) velocity.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) velocity.x += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) velocity.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) velocity.y += speed;

    // Optional: normalize diagonal movement so it isn't faster
    if (velocity.x != 0.f && velocity.y != 0.f)
        velocity *= 0.70710678f; // 1/sqrt(2)
}

void Player::draw(sf::RenderTarget& target) const
{
    target.draw(body);
}