#include "ExitScene.h"

ExitScene::ExitScene()
{

}

ExitScene::~ExitScene()
{
}



bool ExitScene::start()
{

	App::m_running = false;
	return true;
}

void ExitScene::update(float deltaT)
{


	ImGui::End();
}

void ExitScene::render()
{

}

void ExitScene::cleanup()
{
}

