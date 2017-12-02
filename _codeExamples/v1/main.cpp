#include <sfml\Graphics.hpp>
//#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));	/// Make a rectangle called "player".
	player.setFillColor(sf::Color::Red);	/// Give player a color.
	player.setOrigin(50.0f, 50.0f);		/// Set the point player is set at (whether it's placed at top left or middle of player.setPosition etc). Therefore half of player size.

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
			case sf::Event::Closed:				/// Close window.
				window.close();
				break;
			case sf::Event::Resized:			/// Print new window size to console.
				//std::cout << "w|h\t" << evnt.size.width << "|" << evnt.size.height << "\n";
				printf("w|h\t%i|%i\n", evnt.size.width, evnt.size.height);
				break;
			case sf::Event::TextEntered:		/// Input user text.
				if (evnt.text.unicode < 128)	/// Ensure not to include ctrl and other non-text keys (backspace is working, but not updating).
				{
					printf("%c", evnt.text.unicode);
				}
				break;
			}

			/// Close window.
			/*
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
			*/

			/// Keyboard input.
			/*
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				player.move(-1.0f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				player.move(1.0f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				player.move(0.0f, -1.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				player.move(0.0f, 1.0f);
			}
			*/

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));	/// static_cast is a safe, but longer cast that the c style cast '(type)variable'.
			}
		}
	window.clear();
	window.draw(player);
	window.display();
	}


	/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	*/

	return 0;
}