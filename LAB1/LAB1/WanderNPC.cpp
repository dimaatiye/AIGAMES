#include "WanderNPC.h"

WanderNPC::WanderNPC(sf::Texture& WanderTexture) :WanderSprite(WanderTexture)
{
	WanderSprite.setScale({ 0.15,0.15 });
	WanderSprite.setPosition({ 400, 400 });
}
void WanderNPC::draw(sf::RenderWindow& window)
{
	window.draw(WanderSprite);
}