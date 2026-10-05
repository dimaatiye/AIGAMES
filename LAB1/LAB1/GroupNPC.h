#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
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
	float maxscreen = 900.0f;
	float minscreen = 0.0f;
	float randomPos = (rand() % 61 - 30) / 1000.0f; //ranges from -0.030 to 0.030
	float scale = 0.08f;
public:
	GroupNPC(sf::Texture& GroupTexture);
	void update();
	void draw(sf::RenderWindow& window);
	void flock(std::vector<GroupNPC>& npcFlock);

};
