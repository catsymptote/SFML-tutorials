#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)	/// Run Animation animation constructor in parameter list like this.
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(148.0f, 174.0f));	/// Make a rectangle called "player".
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}


Player::~Player()
{
}


void Player::Update(float deltaTime)
{
	//sf::Vector2f movement(0.0f, 0.0f);
	velocity.x *= 0.5f;	/// Will stop the player from moving when button is released, but the closer to 1, the slower they will stop.

	/// Movement with keyboard.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//	movement.y -= speed * deltaTime;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//	movement.y += speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;

		// sqrt(2.0f * gravity * jumpheight)
		velocity.y = -sqrtf(2.0f * 100.0f * 9.81f * jumpHeight);	/// 100.0f because 1m =/= 1 pixel, but more like 100 pixels.
	}

	velocity.y += 100.0f * 9.81f * deltaTime;
	

	/// Idle animation and movement animation.
	if (velocity.x == 0.0f) //&& velocity.y == 0.0f)
	{
		row = 7;	/// Idle
	}
	else
	{
		//if (velocity.y == 0.0f)
		//{
		row = 6;	/// Move left/right

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
		//}
		/*
		if (velocity.x == 0.0f)
		{
			faceRight = true;
			if (velocity.y > 0.0f)
				row = 0;	/// Move down
			else
				row = 4;	/// Move up
		}
		*/
	}
	
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}


void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}


void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		/// Collision on the left.
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		/// Collision on the right.
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		/// Collision on the bottom.
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		/// Collision on the top.
		velocity.y = 0.0f;
	}
}
