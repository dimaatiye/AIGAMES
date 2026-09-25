#pragma once
#include "Player.h"
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
	sf::Vector2f targetPosition{ 450.f, 450.f }; 
	float orientationN = 0.f;
	float maxSpeed = 3.f; 

public:
	NPC(sf::Texture& NPCTexture);
	void update(Player& player);
	void draw(sf::RenderWindow& window);
	void setTargetPosition(const sf::Vector2f& target);
};

