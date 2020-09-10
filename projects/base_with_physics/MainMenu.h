#pragma once

#include "app.h"
#include "kage2dutil/physics.h"
#include "Scene.h"

#define MAIN_MENU_ARRAY_SIZE 3

class MainMenu : public Scene
{
public:
	MainMenu();
	virtual ~MainMenu();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();

	void SetMenuItemColor(int index);

	int currentMenuItemIndex = 0;

	int menuOffset = 0;
	int menuItemOffset = 0;
	sf::Vector2f windowCenter;

	bool previousKeyPressed = false;

	sf::Font font;
	sf::Vector2f windowCentre;
	
	sf::Text menuText[MAIN_MENU_ARRAY_SIZE];



};

