#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
	sf::Sprite PlayerSprite;
	sf::Vector2f velocity;
	float speedx = 0.03f;
	float speedy = 0.03f;
	float rotationSpeed = 2.0f;
	float posX;
	float posY;
public:
	Player(sf::Texture& PlayerTexture);
	void update();
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();

};

