#include <SFML/Graphics.hpp>
#include "main.h"
#include "Player.h"
#include "NPC.h"
#include "WanderNPC.h"
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	sf::RenderWindow window(sf::VideoMode({ 900, 900 }), "LAB1 AIGAMES");
	
	sf::Texture PlayerTexture;
	PlayerTexture.loadFromFile("Graphics/ship.png");
	Player player(PlayerTexture);

	sf::Texture NPCTexture;
	NPCTexture.loadFromFile("Graphics/alien.png");
	NPC NPC(NPCTexture);

	sf::Texture WanderTexture;
	WanderTexture.loadFromFile("Graphics/sc.png");
	WanderNPC WanderNPC(WanderTexture);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}
		window.clear(sf::Color::White);
		player.update();
		NPC.update();
		WanderNPC.updateW();
		player.draw(window);
		NPC.draw(window);
		WanderNPC.draw(window);
		window.display();
	}
}