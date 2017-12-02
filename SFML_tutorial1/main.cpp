#include <sfml\Graphics.hpp>
//#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

	sf::RectangleShape player(sf::Vector2f(148.0f, 174.0f));	/// Make a rectangle called "player".
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture/walk_texture_2.png");
	player.setTexture(&playerTexture);

	sf::Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 7;
	textureSize.y /= 4;

	player.setTextureRect(sf::IntRect(textureSize.x * 6, textureSize.y * 2, textureSize.x, textureSize.y));


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