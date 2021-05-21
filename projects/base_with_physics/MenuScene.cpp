#include "MenuScene.h"
#include "kage2dutil/texture_manager.h"
#include <iostream>
MenuScene::MenuScene()
{
}

void MenuScene::Load()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(2, 2);

}

void MenuScene::Update()
{
}

void MenuScene::Render(sf::RenderWindow& m_window)
{
	std::cout << "menu" << std::endl;
	m_window.draw(*m_backgroundSprite);

}

