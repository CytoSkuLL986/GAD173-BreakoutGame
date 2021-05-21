#include "GameScene.h"
#include "kage2dutil/texture_manager.h"
#include <string>
#include "sstream"
#include "fstream"

#include <iostream>

using namespace std;

GameScene::GameScene()
{
}

void GameScene::Load(){


//Retrieving the created button textures and assigning them to the pointers made for them (currently in Example.h).
sapphire = kage::TextureManager::getTexture("data/sapphire.png");
diamond = kage::TextureManager::getTexture("data/diamond.png");
stone = kage::TextureManager::getTexture("data/stone.png");
questionMark = kage::TextureManager::getTexture("data/questionMark.png");

string line;
ifstream myfile("map.data");

if (myfile.is_open())
{

	int index = 0;
	int mapIndex = 0;

	int x = 0;
	int y = 0;
	while (std::getline(myfile, line))
	{

		while (index <= line.length()) {
			index = line.find(", "); // finds location of the comma and space! :D

			std::string word = line.substr(0, index); // starts from where we want to extract characters

			line = line.substr(index + 2); // updates itself to remove what we initially processed 

			int value = std::stoi(word);// converts string to an integer 

			//switch statement for associating tile textues with different tileIDs, and switching between them.
			switch (value)
			{
			case 0:
				break;
			case 1:
				tiles[mapIndex].sprite.setTexture(*sapphire);
				break;
			case 2:
				tiles[mapIndex].sprite.setTexture(*diamond);
				break;
			case 3:
				tiles[mapIndex].sprite.setTexture(*stone);
				break;

			default:
				tiles[mapIndex].sprite.setTexture(*questionMark);
				break;
			}

			tiles[mapIndex].sprite.setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));
			tiles[mapIndex].id = value;
			//std::cout << "index: " << mapIndex << " - " << word << std::endl;
			mapIndex++;
			x++;

			if (x >= TOTAL_CELLS_X - 1) {
				y++;
				x = 0;
			}
		}

		//cout << line << '\n';
	}
	myfile.close();
}
}

void GameScene::Update()
{
}

void GameScene::Render(sf::RenderWindow& m_window)
{
	std::cout << "game" << std::endl;
	for (size_t i = 0; i < TILES_ARRAY_SIZE; i++)
	{
		m_window.draw(tiles[i].sprite);
	}
}
