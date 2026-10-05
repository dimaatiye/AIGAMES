#include "GroupNPC.h"

GroupNPC::GroupNPC(sf::Texture& GroupTexture)
	:GroupNPCSprite(GroupTexture)
{

	posX = static_cast<float>(rand() % 800);
	posY = static_cast<float>(rand() % 800);

	GroupNPCSprite.setScale({ scale , scale });
	GroupNPCSprite.setPosition({ posX, posY });
	GroupNPCSprite.setRotation(sf::degrees(0));

	speedx = randomPos;
	speedy = randomPos;

	velocity = { speedx, speedy };
}
void GroupNPC::update()
{
	GroupNPCSprite.move(velocity);
	sf::FloatRect bounds = GroupNPCSprite.getGlobalBounds();
	sf::Vector2f position = GroupNPCSprite.getPosition();
	if (bounds.position.x + bounds.size.x > maxscreen)
	{
		GroupNPCSprite.setPosition({ maxscreen - bounds.size.x, position.y });
		velocity.x = -velocity.x;
	}
	if (bounds.position.y < minscreen)
	{
		GroupNPCSprite.setPosition({ position.x, minscreen });
		velocity.y = -velocity.y;
	}

	if (bounds.position.y + bounds.size.y > maxscreen)
	{
		GroupNPCSprite.setPosition({ position.x, maxscreen - bounds.size.y });
		velocity.y = -velocity.y;
	}

	if (bounds.position.x < minscreen)
	{
		GroupNPCSprite.setPosition({ minscreen, position.y });
		velocity.x = -velocity.x;//bounce back
	}
}
void GroupNPC::draw(sf::RenderWindow& window)
{
	window.draw(GroupNPCSprite);
}

void GroupNPC::flock(std::vector<GroupNPC>& npcFlock)
{
}
