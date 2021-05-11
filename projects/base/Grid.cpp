#include "Grid.h"
#include <iostream>

Grid::Grid()														//: line(sf::Vector2f(100, 2))
{
	for (size_t i = 0; i < HORIZONTAL_ARRAY_SIZE; i++)
	{
		horizontal_lines[i].setSize(sf::Vector2f(HORIZONTAL_LINE_SIZE_X, HORIZONTAL_LINE_SIZE_Y));
		horizontal_lines[i].setPosition(
			sf::Vector2f
			(HORIZONTAL_LINE_POSITION_X , 
			HORIZONTAL_LINE_POSITION_Y + i * HORIZONTAL_Y_SPACING));
	}
}

Grid::~Grid()
{

}

void Grid::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < HORIZONTAL_ARRAY_SIZE; i++)
	{
		window.draw(horizontal_lines[i]);
	}
}