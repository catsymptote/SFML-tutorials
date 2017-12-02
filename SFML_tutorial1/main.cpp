#include <sfml\Graphics.hpp>
#include "Animation.h"
//#include <iostream>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

	sf::RectangleShape player(sf::Vector2f(148.0f, 174.0f));	/// Make a rectangle called "player".
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture/walk_texture_2.png");
	player.setTexture(&playerTexture);
	/// Change sprite image: Change playerTexture file directory and the size in imgCount(w, h).
	sf::Vector2u imgCount(7, 4);

	Animation animation(&playerTexture, imgCount, 1.0f/(float(imgCount.x) * float(imgCount.y)));

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

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear(sf::Color(150, 150, 150));
		window.draw(player);
		window.display();
	}

	return 0;
}