#include <sfml\Graphics.hpp>
#include "Player.h"
//#include <iostream>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

	/// Change sprite image: Change playerTexture file directory and w, h.
	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture/movement2.png");
	
	int w = 12, h = 4;
	sf::Vector2u imgCount(w, h);

	Player player(&playerTexture, imgCount, 1.0f/(float(w)), 100.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	/// Game loop.
	while (window.isOpen())
	{
		/// Reset texture clock.
		deltaTime = clock.restart().asSeconds();

		/// Create event and event loop.
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			/// Event type stuffs
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		player.Update(deltaTime);

		window.clear(sf::Color(150, 150, 150));
		player.Draw(window);
		window.display();
	}

	return 0;
}