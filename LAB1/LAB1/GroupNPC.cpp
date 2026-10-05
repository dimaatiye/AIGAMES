#include "GroupNPC.h"
GroupNPC::GroupNPC(sf::Texture& GroupTexture)
	:GroupNPCSprite(GroupTexture)
{

	posX = static_cast<float>(rand() % 800);
	posY = static_cast<float>(rand() % 800);

	GroupNPCSprite.setScale({ 0.1f , 0.1f });
	GroupNPCSprite.setPosition({ posX, posY });
	GroupNPCSprite.setRotation(sf::degrees(0));

	speedx = (rand() % 61 - 30) / 1000.0f; //ranges from -0.030 to 0.030
	speedy = (rand() % 61 - 30) / 1000.0f;

	velocity = { speedx, speedy };
}
void GroupNPC::update()
{
	GroupNPCSprite.move(velocity);
	sf::FloatRect bounds = GroupNPCSprite.getGlobalBounds();
	sf::Vector2f position = GroupNPCSprite.getPosition();
	if (bounds.position.x + bounds.size.x > 900)
	{
		GroupNPCSprite.setPosition({ 900 - bounds.size.x, position.y });
		velocity.x = -velocity.x;
	}
	if (bounds.position.y < 0)
	{
		GroupNPCSprite.setPosition({ position.x, 0 });
		velocity.y = -velocity.y;
	}

	if (bounds.position.y + bounds.size.y > 900)
	{
		GroupNPCSprite.setPosition({ position.x, 900 - bounds.size.y });
		velocity.y = -velocity.y;
	}

	if (bounds.position.x < 0)
	{
		GroupNPCSprite.setPosition({ 0, position.y });
		velocity.x = -velocity.x;//bounce back
	}
}
void GroupNPC::draw(sf::RenderWindow& window)
{
	window.draw(GroupNPCSprite);
}