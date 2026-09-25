#include "NPC.h"
NPC::NPC(sf::Texture& NPCTexture)
	:NPCSprite(NPCTexture)
{
	posX = static_cast<float>(rand() % 800);
	posY = static_cast<float>(rand() % 800);

	NPCSprite.setPosition({ 400, 100 });
	NPCSprite.setScale({ 0.15,0.15 });

	speedx = (rand() % 61 - 30) / 1000.0f; 
	speedy = (rand() % 61 - 30) / 1000.0f;

	velocity = { speedx, speedy };
}

void NPC::update(Player& player)
{
	sf::Vector2f playerPosition = player.getPosition();

	sf::Vector2u windowSize = { 900, 900 };
	sf::FloatRect bounds = NPCSprite.getGlobalBounds();
	sf::Vector2f position = NPCSprite.getPosition();
	if (bounds.position.x < -1 ||
		bounds.position.x + bounds.size.x > 900)
	{
		velocity.x = -velocity.x;
	}

	if (bounds.position.y < -1 ||
		bounds.position.y + bounds.size.y > 900)
	{
		velocity.y = -velocity.y;
	}
	
}
void NPC::draw(sf::RenderWindow& window)
{
	window.draw(NPCSprite);
}

void NPC::setTargetPosition(const sf::Vector2f& target)
{
}
