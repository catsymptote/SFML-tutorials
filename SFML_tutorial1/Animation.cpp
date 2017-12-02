#include "Animation.h"


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	currentImage.y = 0;

	uvRect.width	= texture->getSize().x / float(imageCount.x);
	uvRect.height	= texture->getSize().y / float(imageCount.y);
}


Animation::~Animation()
{
}


void Animation::Update(int row, float deltaTime, bool faceRight)
{
	/// When using single row animations.
	currentImage.y = row;

	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		/// When using multirow sprites.
		/*
		if(currentImage.x == imageCount.x && currentImage.y == imageCount.y)
		{
			currentImage.x = 0;
			currentImage.y = 0;
		}
		*/

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;

			/// When using multirow sprites.
			/*
			currentImage.y++;
			if (currentImage.y >= imageCount.y -1)
			{
				currentImage.y = 0;
			}
			*/
		}
	}
	uvRect.top = currentImage.y * uvRect.height;
	
	if(faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x +1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}