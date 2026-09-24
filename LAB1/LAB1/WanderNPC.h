#pragma once
#include <SFML/Graphics.hpp>
class WanderNPC
{private :
	sf::Sprite WanderSprite;
	float orientationW = 0.0f;;
	float wanderOrientation = 0.0f;;
	float wanderRate = 0.1f;;
	float maxAcceleration = 200.0f;
	float wanderRadius = 50.0f;
	float wanderOffset = 100.0f;
	sf::Vector2f velocityW{ 0.0f, 0.0f };
	float maxSpeed = 200.0f;
	sf::Clock clockW;
	sf::FloatRect bounds;
public:
	WanderNPC(sf::Texture& WanderTexture);
	void updateW();
	void draw(sf::RenderWindow& window);
};

