#include <sfml\Graphics.hpp>
//#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));	/// Make a rectangle called "player".
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture/linux_logo.png");
	player.setTexture(&playerTexture);


	/// Game loop.
	while (window.isOpen())
	{
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

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}