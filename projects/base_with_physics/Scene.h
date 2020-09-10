#pragma once
#include "kage2dutil/gameobject.h"
#include <SFML/Graphics.hpp>

class Scene 
{
public:
	sf::RenderWindow* m_window;


	Scene();
	virtual ~Scene();

	virtual bool start() = 0;
	virtual void update(float deltaT) = 0;
	virtual void render() = 0;
	virtual void cleanup() = 0;
};
