#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
	sf::Sprite* m_backgroundSprite;

public:
	MenuScene();
	 void Load() override;
	 void Update() override;
	 void Render(sf::RenderWindow& m_window) override;

};

