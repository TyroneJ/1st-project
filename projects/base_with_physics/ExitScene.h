#pragma once

#include "app.h"
#include "kage2dutil/physics.h"
#include "Scene.h"

class ExitScene : public Scene
{

	public:

		ExitScene();
		virtual ~ExitScene();
		virtual bool start();
		virtual void update(float deltaT);
		virtual void render();
		virtual void cleanup();

		
	};


