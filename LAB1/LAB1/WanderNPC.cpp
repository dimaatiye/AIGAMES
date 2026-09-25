#include "WanderNPC.h"
#include <cmath>

WanderNPC::WanderNPC(sf::Texture& WanderTexture) :WanderSprite(WanderTexture)
{
	WanderSprite.setScale({ 0.15,0.15 });
	bounds = WanderSprite.getLocalBounds();
	WanderSprite.setOrigin({ bounds.size.x / 2.f, bounds.size.y / 2.f }); // rotate around the centre

	WanderSprite.setPosition({ 400, 400 });
}
void WanderNPC::updateW()
{
	float dt = clockW.restart().asSeconds();

	//lecture: wanderOrientation += random(-1,+1) * wanderRate
	float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
	wanderOrientation += r * wanderRate;

	//lecture: targetOrientation = wanderOrientation + orientation
	float targetOrientation = wanderOrientation + orientationW;

	// lecture: target = my.position + wanderOffset * my.orientation.asVector()
	sf::Vector2f facing(std::cos(orientationW), std::sin(orientationW));
	sf::Vector2f circleCentre = WanderSprite.getPosition() + wanderOffset * facing;

	sf::Vector2f targetFacing(std::cos(targetOrientation), std::sin(targetOrientation));
	sf::Vector2f target = circleCentre + wanderRadius * targetFacing;

	sf::Vector2f toTarget = target - WanderSprite.getPosition();
	float desiredOrientation = std::atan2(toTarget.y, toTarget.x);

	float rotationDiff = std::atan2(std::sin(desiredOrientation - orientationW),std::cos(desiredOrientation - orientationW));

	float maxRotation = 1.5f * dt; 
	if (rotationDiff > maxRotation)
	{
		rotationDiff = maxRotation;
	}
	if (rotationDiff < -maxRotation) 
	{
		rotationDiff = -maxRotation;
	}


	orientationW += rotationDiff;

	//acceleration in the direction sprite now facing
	sf::Vector2f acceleration = maxAcceleration * sf::Vector2f(std::cos(orientationW), std::sin(orientationW));

	
	float damping = 3.0f; 
	velocityW += acceleration * dt;
	velocityW -= velocityW * damping * dt; 
	float speed = std::sqrt(velocityW.x * velocityW.x + velocityW.y * velocityW.y);
	if (speed > maxSpeed)
	{
		velocityW *= (maxSpeed / speed);
	}

	WanderSprite.move(velocityW * dt);
	WanderSprite.setRotation(sf::radians(orientationW) + sf::degrees(90.f)); 
	sf::FloatRect currentBounds = WanderSprite.getGlobalBounds();

	if (currentBounds.position.x < -1 ||
		currentBounds.position.x + currentBounds.size.x > 900)
	{
		velocityW.x = -velocityW.x;

	}

	if (currentBounds.position.y < -1 ||
		currentBounds.position.y + currentBounds.size.y > 900)
	{
		velocityW.y = -velocityW.y;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
	{
		isVisible = false;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)))
		isVisible = true;
}
void WanderNPC::draw(sf::RenderWindow& window)
{
	if (isVisible)
	window.draw(WanderSprite);
}