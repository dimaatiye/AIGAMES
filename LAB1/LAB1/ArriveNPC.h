#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
class ArriveNPC
{
private:
	sf::Sprite ArriveSprite;
	sf::Vector2f velocity;
	float speedxA = 0.02f;
	float speedyA = 0.21f;
	float rotationSpeed = 2.0f;
	float posX;
	float posY;
	float orientationA = 0.f;
	float maxSpeed = 0.03f;
	sf::Vector2f direction;
	bool isVisible = true;
	float timeToTarget = 0.25f;
	float raduis = 10.0f;
	sf::Clock clock;

public:
	ArriveNPC(sf::Texture& ArriveTexture);
	void update(Player& player);
	void draw(sf::RenderWindow& window);
	void setMaxSpeed(float speed);
	void setPosition(sf::Vector2f position);
};

