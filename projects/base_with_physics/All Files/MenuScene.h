#pragma once
#include "Scene.h"

//This class inherits from the Scenes class. It has inheritted all 3 functions written here, as they all
//already exist within the Scenes class.
class MenuScene : public Scene
{
	sf::Sprite* m_backgroundSprite;

public:
	MenuScene();
	 void Load() override;
	 void Update() override;
	 void Render(sf::RenderWindow& m_window) override;

};

