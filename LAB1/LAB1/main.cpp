#include <SFML/Graphics.hpp>
#include "main.h"
#include "Player.h"
#include "NPC.h"
#include "WanderNPC.h"
#include "ArriveNPC.h"
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	sf::RenderWindow window(sf::VideoMode({ 900, 900 }), "LAB1 AIGAMES");
	
	sf::Texture PlayerTexture;
	PlayerTexture.loadFromFile("Graphics/ship.png");
	Player player(PlayerTexture);

	sf::Texture NPCTexture;
	NPCTexture.loadFromFile("Graphics/alien2.png");
	NPC NPC(NPCTexture);

	sf::Texture WanderTexture;
	WanderTexture.loadFromFile("Graphics/sc.png");
	WanderNPC WanderNPC(WanderTexture);

	sf::Texture ArriveTexture;
	ArriveTexture.loadFromFile("Graphics/alien.png");
	ArriveNPC Arrive1(ArriveTexture);
	Arrive1.setPosition({ 300,300 });
	Arrive1.setMaxSpeed(200.0F);
	sf::Texture ArriveTexture2;
	ArriveTexture2.loadFromFile("Graphics/alien.png"); 
	ArriveNPC Arrive2(ArriveTexture2);
	Arrive2.setPosition({ 600, 600 });
	Arrive2.setMaxSpeed(80.f);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		player.update();
		NPC.update(player);
		WanderNPC.updateW();
		Arrive1.update(player);
		Arrive2.update(player);
		player.draw(window);
		NPC.draw(window);
		WanderNPC.draw(window);
		Arrive1.draw(window);
		Arrive2.draw(window);
		window.display();
	}
}