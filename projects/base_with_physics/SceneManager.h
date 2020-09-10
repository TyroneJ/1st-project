#pragma once
#include <vector>
#include "app.h"
#include "Scene.h"


class SceneManager : public App
{

public:
	SceneManager();

	virtual ~SceneManager();

	void AddNewScene(Scene* scene);
	void RemoveScene();
	static void Run(int index);
	

	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();

};

