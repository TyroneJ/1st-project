#pragma once

#include "app.h"

#define GRID_OFFSET_X 0
#define GRID_OFFSET_Y 0


#define CELL_COUNT_X 10
#define CELL_COUNT_Y 10

#define CELL_WIDTH 64
#define CELL_HEIGHT 64

#define CELL_TOTAL_COUNT CELL_COUNT_X * CELL_COUNT_Y

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;
	sf::Sprite* m_catSprite;
	sf::Texture* m_catTexture;

	sf::Sprite tiles[CELL_TOTAL_COUNT];
	sf::RectangleShape line[CELL_COUNT_X];
	sf::RectangleShape linehorizontal[CELL_COUNT_Y];
};
