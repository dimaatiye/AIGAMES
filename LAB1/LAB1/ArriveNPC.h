#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
class ArriveNPC
{
private:
	sf::Sprite ArriveSprite;
	sf::Vector2f velocity;
	float speedxA = 0.01f;
	float speedyA = 0.01f;
	float rotationSpeed = 2.0f;
	float posX;
	float posY;
	float orientationA = 0.f;
	float maxSpeed = 0.02f;
	sf::Vector2f direction;
	bool isVisible = true;


public:
	ArriveNPC(sf::Texture& ArriveTexture);
	void update(Player& player);
	void draw(sf::RenderWindow& window);
};

