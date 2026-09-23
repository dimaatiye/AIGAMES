#pragma once
#include <SFML/Graphics.hpp>
class NPC
{
private:
	sf::Sprite NPCSprite;
	sf::Vector2f velocity;
	float speedx = 0.03f;
	float speedy = 0.03f;
	float rotationSpeed = 2.0f;
	float posX;
	float posY;
	float orientationW;
public:
	NPC(sf::Texture& NPCTexture);
	void update();
	void draw(sf::RenderWindow& window);
};

