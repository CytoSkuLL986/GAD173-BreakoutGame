#pragma once
#include "Scene.h"
#include "app.h"
#include <vector>

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	void Load(int index);
	static Example &inst();

	std::vector<Scene*> scenes;

	int currentSceneIndex = -1;


};
