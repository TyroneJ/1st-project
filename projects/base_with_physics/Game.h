#pragma once

#include "app.h"
#include "kage2dutil/physics.h"
#include "Scene.h"

class Game : public	Scene
{

public:

	Game();
	virtual ~Game();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Game &inst();
};
