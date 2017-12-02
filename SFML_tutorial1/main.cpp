#include <sfml\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"



static const float VIEW_HEIGHT = 512.0f;


void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	/// Change sprite image: Change playerTexture file directory and w, h.
	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture/movement4.png");
	
	int w=9, h=8;
	sf::Vector2u imgCount(w, h);

	Player player(&playerTexture, imgCount, 1.0f/(float(w)), 100.0f, 200.0f);

	std::vector<Platform> platforms;

	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	//Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	//Platform platform3(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));


	float deltaTime = 0.0f;
	sf::Clock clock;

	/// Game loop.
	while (window.isOpen())
	{
		/// Reset texture clock.
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)	/// Do this to force a minimum amount of fps (to fix the problem of the player falling through the floor when moving window).
			deltaTime = 1.0f / 20.0f;

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
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}

		player.Update(deltaTime);

		sf::Vector2f direction;

		///	These two for loops are essentially the same (except for the internal functionality in the second loop.
		//	for(int i = 0; i < platforms.size(); i++
		//	{
		//		Platform& platform = platforms[i];
		//	}

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		view.setCenter(player.GetPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		player.Draw(window);
		
		for (Platform& platform : platforms)
			platform.Draw(window);

		window.display();
	}

	return 0;
}
