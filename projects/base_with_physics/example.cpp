#include "example.h"
#include "MenuScene.h"
#include "GameScene.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}


bool Example::start()
{
	scenes.push_back(new MenuScene());
	scenes.push_back(new GameScene());
		
	Load(0); //default scene 
	return true;
}

void Example::Load(int index) {
	currentSceneIndex = index;
	scenes[currentSceneIndex]->Load();
}

void Example::update(float deltaT)
{
	// You need to update the physics system every game update

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if (ImGui::Button("Menu")) {
		Load(0);
	} else if (ImGui::Button("Level 1")) {
		Load(1);
	} else if(ImGui::Button("Exit")) { 
		m_running = false;
	}
	ImGui::End();
	if (currentSceneIndex >= 0) {
		scenes[currentSceneIndex]->Update();
	}
}

void Example::render()
{

	if (currentSceneIndex >= 0) {
		scenes[currentSceneIndex]->Render(m_window);
	}

}

void Example::cleanup()
{

}

