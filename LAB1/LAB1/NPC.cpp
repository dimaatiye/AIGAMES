#include "NPC.h"
NPC::NPC(sf::Texture& NPCTexture)
	:NPCSprite(NPCTexture)
{
	posX = static_cast<float>(rand() % 800);
	posY = static_cast<float>(rand() % 800);

	NPCSprite.setPosition({ 100, 100 });
	NPCSprite.setScale({ 0.055,0.055 });

	//speedx = (rand() % 61 - 30) / 1000.0f; 
	//speedy = (rand() % 61 - 30) / 1000.0f;

	//velocity = { speedx, speedy };
}

void NPC::update(Player& player)
{
	sf::Vector2f playerPosition = player.getPosition();
	sf::Vector2f position = NPCSprite.getPosition();
	sf::Vector2u windowSize = { 900, 900 };
	sf::FloatRect bounds = NPCSprite.getGlobalBounds();

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
	direction = playerPosition - position;
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length > 0)
	{
		direction /= length;
	}
	velocity = direction * maxSpeed;
	NPCSprite.move(velocity);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
	{
		isVisible = false;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)))
		isVisible = true;
}
void NPC::draw(sf::RenderWindow& window)
{
	if (isVisible)
		window.draw(NPCSprite);
}
