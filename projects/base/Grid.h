#pragma once
#include <SFML/Graphics.hpp>

#define HORIZONTAL_ARRAY_SIZE 10
//#define VERTICLE_ARRAY_SIZE

#define HORIZONTAL_LINE_SIZE_X 1920
#define HORIZONTAL_LINE_SIZE_Y 2

#define HORIZONTAL_LINE_POSITION_X 0
#define HORIZONTAL_LINE_POSITION_Y 100

#define HORIZONTAL_Y_SPACING 50


class Grid
{
public:
	Grid();
	~Grid();

	void Draw(sf::RenderWindow& window);
	sf::RectangleShape horizontal_lines[HORIZONTAL_ARRAY_SIZE];

};

