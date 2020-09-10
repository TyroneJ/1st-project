#include "cmath"
#include "kf/kf_log.h"
#include "SceneManager.h"
#include "Game.h"
#include "MainMenu.h"
#include "ExitScene.h"

using namespace std;

int main()
{
	SceneManager sceneManager;


	MainMenu* mainMenu = new MainMenu();
	Game* game = new Game();
	ExitScene* exitScene = new ExitScene();
	
	sceneManager.AddNewScene(mainMenu);
	sceneManager.AddNewScene(game);
	sceneManager.AddNewScene(exitScene);
	sceneManager.AddNewScene(exitScene);

	sceneManager.Run(0);

	sceneManager.run();

	return 0;
}
