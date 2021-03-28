/*
#pragma once
#include <SFML/Graphics.hpp>
#include "example.h"

constexpr float ballRadius{ 10.f }, ballVelocity{ 7.f };

struct Ball
{
	sf::CircleShape ballShape;
	sf::Vector2f velocity{ -ballVelocity, -ballVelocity };

	Ball(float mX, float mY)
	{
		ballShape.setPosition(mX, mY);
		ballShape.setRadius(ballRadius);
		ballShape.setFillColor(sf::Color::Red);
		ballShape.setOrigin(ballRadius, ballRadius);
	}
};

void update();
*/