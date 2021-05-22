#pragma once
#include "SFML/Graphics.hpp"

//The base class from which the Gamescenes (and consequent scenes) will inherit from.
class Scene
{
public:
	Scene();
	virtual void Load();
	virtual void Update();
	virtual void Render(sf::RenderWindow &m_window);

};

