#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
}



bool Game::start()
{
	
	

	return true;
}

void Game::update(float deltaT)
{


	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		App::m_running = false;
	}
	
	ImGui::End();
}

void Game::render()
{
	
}

void Game::cleanup()
{
	
}

