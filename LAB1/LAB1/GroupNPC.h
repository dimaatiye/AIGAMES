#pragma once
#include <SFML/Graphics.hpp>
class GroupNPC
{
private:
	sf::Sprite GroupNPCSprite;
	sf::Vector2f velocity;
	float speedx = 0.03f;
	float speedy = 0.03f;
	float rotationSpeed = 2.0f;
	float posX;
	float posY;
public:
	GroupNPC(sf::Texture& GroupTexture);
	void update();
	void draw(sf::RenderWindow& window);

};
