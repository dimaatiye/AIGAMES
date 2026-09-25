#include "ArriveNPC.h"
#include <iostream>
ArriveNPC::ArriveNPC(sf::Texture& ArriveTexture)
	:ArriveSprite(ArriveTexture)
{
	ArriveSprite.setPosition({ 400, 400 });
	ArriveSprite.setScale({ 0.15,0.15 });

}
void ArriveNPC::update(Player& player)
{
    float dt = clock.restart().asSeconds();
    sf::Vector2f playerPosition = player.getPosition();
    sf::Vector2f position = ArriveSprite.getPosition();
    velocity = playerPosition - position;

    float length = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

    if (length < raduis)
    {
        velocity = { 0, 0 };
    }
    else
    {
        velocity /= timeToTarget;

        float speed = std::sqrt(
            velocity.x * velocity.x +
            velocity.y * velocity.y
        );

        if (speed > maxSpeed)
        {
            velocity /= speed;
            velocity *= maxSpeed;
        }
    }
    ArriveSprite.move(velocity * dt);

}

void ArriveNPC::setMaxSpeed(float speed)
{
    maxSpeed = speed;
}

void ArriveNPC::setPosition(sf::Vector2f position)
{
	ArriveSprite.setPosition(position);

}
void ArriveNPC::draw(sf::RenderWindow& window)
{

    window.draw(ArriveSprite);
}