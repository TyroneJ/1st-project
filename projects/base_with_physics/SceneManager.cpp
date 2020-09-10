#include "SceneManager.h"

static int currentRunningScene= 0;
static std::vector<Scene*> scenes;


SceneManager::SceneManager() : App()
{

}

SceneManager::~SceneManager()
{

}

void SceneManager::AddNewScene(Scene* scene)
{
	scenes.push_back(scene);
	scene->m_window = &m_window;
}


void SceneManager::RemoveScene()
{

}

void SceneManager::Run(int index)
{
	currentRunningScene = index;
	scenes[currentRunningScene]->start();

}

bool SceneManager::start()
{
	return scenes[currentRunningScene]->start();

}

void SceneManager::update(float deltaT)
{
	scenes[currentRunningScene]->update(deltaT);
}

void SceneManager::render()
{
	scenes[currentRunningScene]->render();

}

void SceneManager::cleanup()
{
	scenes[currentRunningScene]->cleanup();

}