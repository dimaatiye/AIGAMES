#include "WanderNPC.h"

WanderNPC::WanderNPC(sf::Texture& WanderTexture) :WanderSprite(WanderTexture)
{
	WanderSprite.setScale({ 0.15,0.15 });
	WanderSprite.setPosition({ 400, 400 });
	orientationW = 0.0f;
	wanderOrientation = 0.0f;
	wanderRate = 0.1f;
	wanderOffset = 100.0f;
	wanderRadius = 50.0f;
}
void WanderNPC::draw(sf::RenderWindow& window)
{
	window.draw(WanderSprite);
}