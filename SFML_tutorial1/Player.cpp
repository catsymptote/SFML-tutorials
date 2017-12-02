#include "Player.h"



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)	/// Run Animation animation constructor in parameter list like this.
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(148.0f, 174.0f));	/// Make a rectangle called "player".
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}


Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	/// Movement with keyboard.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;

	/// Idle animation and movement animation.
	if (movement.x == 0.0f && movement.y == 0.0f)
	{
		row = 0;
	}
	else
	{
		if (movement.y == 0.0f)
		{
			row = 2;

			if (movement.x > 0.0f)
				faceRight = true;
			else
				faceRight = false;
		}
		if (movement.x == 0.0f)
		{
			faceRight = true;
			if (movement.y > 0.0f)
				row = 0;
			else
				row = 3;
		}
		
	}
	

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
