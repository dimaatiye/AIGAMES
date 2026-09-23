#pragma once
#include <SFML/Graphics.hpp>
class WanderNPC
{private :
	sf::Sprite WanderSprite;
	float orientationW;
	float wanderOrientation;
	float wanderRate;
	float maxAcceleration;
	float wanderRadius;
	float wanderOffset;
public:
	WanderNPC(sf::Texture& WanderTexture);
	void update();
	void draw(sf::RenderWindow& window);
};

