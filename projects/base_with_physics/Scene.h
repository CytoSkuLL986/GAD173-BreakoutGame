#pragma once
#include "SFML/Graphics.hpp"
class Scene
{
public:
	Scene();
	virtual void Load();
	virtual void Update();
	virtual void Render(sf::RenderWindow &m_window);

};

