#pragma once
#include "Scene.h"

#define LINE_THICKNESS 3

//As of now, Offsets are set 0, as they where creating unnecessary complications for during debugging.
//I have kept the defines for future testing.
#define GRID_OFFSET_X 0
#define GRID_OFFSET_Y 0

#define CELL_WIDTH 110
#define CELL_HEIGHT 50

#define TOTAL_CELLS_X 15 + 1
#define	TOTAL_CELLS_Y 15 + 1

#define TILES_ARRAY_SIZE (TOTAL_CELLS_X - 1) * (TOTAL_CELLS_Y - 1)

class GameScene : public Scene
{

	struct Tile
	{
		int id = 0;
		sf::Sprite sprite;
	};

public:
	GameScene();

	//pointers for tile textures
	sf::Texture* sapphire = nullptr;
	sf::Texture* diamond = nullptr;
	sf::Texture* stone = nullptr;
	sf::Texture* questionMark = nullptr;

	//Below we have created the array of tiles (for grid-slots)
	Tile tiles[TILES_ARRAY_SIZE];

	

	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& m_window) override;
	
};

