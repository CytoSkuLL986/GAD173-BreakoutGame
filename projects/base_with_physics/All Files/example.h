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

	//This is a list that stores pointers to scenes.
	std::vector<Scene*> scenes;

	//This is the variable that we will be able to change in order to switch around between our created
	//scenes. It is initialized at -1, so that it is not currently defined to a scene (scene array / list 
	//begins at 0).
	int currentSceneIndex = -1;


};
