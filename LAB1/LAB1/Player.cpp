#include "Player.h"
#include <cstdlib>

Player::Player(sf::Texture& PlayerTexture)
	:PlayerSprite(PlayerTexture)
{
	posX = static_cast<float>(rand() % 800) ;
	posY = static_cast<float>(rand() % 800 );

	PlayerSprite.setScale({ 0.3f,0.3f });
	PlayerSprite.setPosition({ posX, posY });
	PlayerSprite.setRotation(sf::degrees(0));

	speedx = (rand() % 61 - 30) / 1000.0f; //ranges from -0.030 to 0.030
	speedy = (rand() % 61 - 30) / 1000.0f;

	velocity = { speedx, speedy };
}

void Player::update()
{
	PlayerSprite.move(velocity);

	sf::Vector2u windowSize = { 900, 900 };
	float playerSpeed = 0.06f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		PlayerSprite.move({ static_cast<float> ( -playerSpeed - 0.030f), 0 });
		PlayerSprite.setRotation(sf::degrees(-20));

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		PlayerSprite.move({ static_cast<float>(playerSpeed + 0.050f), 0 });
		PlayerSprite.setRotation(sf::degrees(20));

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		PlayerSprite.move({ 0, static_cast<float>(-playerSpeed - 0.030f) });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		PlayerSprite.move({ 0, static_cast<float>(playerSpeed +0.030f) });
	}

	sf::FloatRect bounds = PlayerSprite.getGlobalBounds();
	sf::Vector2f position = PlayerSprite.getPosition();

	if (bounds.position.x < 0)
	{
		PlayerSprite.setPosition({ 0, position.y });
		velocity.x = -velocity.x;//bounce back
	}

	if (bounds.position.x + bounds.size.x > 900)
	{
		PlayerSprite.setPosition({ 900 - bounds.size.x, position.y });
		velocity.x = -velocity.x;
	}
	if (bounds.position.y < 0)
	{
		PlayerSprite.setPosition({ position.x, 0 });
		velocity.y = -velocity.y;
	}

	if (bounds.position.y + bounds.size.y > 900)
	{
		PlayerSprite.setPosition({ position.x, 900 - bounds.size.y });
		velocity.y = -velocity.y;
	}

}
void Player::draw(sf::RenderWindow& window)
{
	window.draw(PlayerSprite);
}

sf::Vector2f Player::getPosition()
{
	return PlayerSprite.getPosition();
}
