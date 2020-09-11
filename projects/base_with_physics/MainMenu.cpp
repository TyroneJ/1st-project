#include "MainMenu.h"
#include "SceneManager.h"


MainMenu::MainMenu() 
{

}

MainMenu::~MainMenu()
{

}


bool MainMenu::start()
{


	if (!font.loadFromFile("data/ProggyTiny.ttf"))
	{
		std::cout << "Failed to load ProggyTiny font" << std::endl;
	}


	menuOffset = 200;
	menuItemOffset = 100;
	windowCenter = sf::Vector2f(m_window->getSize().x / 2, m_window->getSize().y / 2);


	menuText[0].setString("PLAY");
	menuText[1].setString("OPTIONS");
	menuText[2].setString("EXIT");

	for (size_t i = 0; i < MAIN_MENU_ARRAY_SIZE; i++)
	{
		menuText[i].setFont(font);
		menuText[i].setColor(sf::Color(128, 128, 128));
		menuText[i].setPosition(sf::Vector2f(
			windowCenter.x - (menuText[i].getGlobalBounds().width / 2),
			windowCenter.y - (menuText[i].getGlobalBounds().height / 2) + (menuItemOffset * i) + menuOffset));
	}

	menuText[currentMenuItemIndex].setColor(sf::Color(255, 255, 255));

	return true;

}

void MainMenu::SetMenuItemColor(int index)
{
	for (size_t i = 0; i < MAIN_MENU_ARRAY_SIZE; i++)
	{
		menuText[i].setColor(sf::Color(128, 128, 128));

	}
	menuText[index].setColor(sf::Color(255, 255, 255));
}

void MainMenu::update(float deltaT)
{
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !previousKeyPressed)
		{

				currentMenuItemIndex--;

				if (currentMenuItemIndex < 0)
					currentMenuItemIndex = MAIN_MENU_ARRAY_SIZE - 1;


				SetMenuItemColor(currentMenuItemIndex);

				previousKeyPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !previousKeyPressed)
		{
			currentMenuItemIndex++;

			if (currentMenuItemIndex > MAIN_MENU_ARRAY_SIZE - 1)
				currentMenuItemIndex = 0;

			SetMenuItemColor(currentMenuItemIndex);

			previousKeyPressed = true;

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			SceneManager::Run(currentMenuItemIndex + 1);
		}



		if (App::iskeyReleased)
		{
			previousKeyPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window->hasFocus())
		{
			App::m_running = false;

		}
		ImGui::Begin("Kage2D");

		if (ImGui::Button("Exit"))
		{
			App::m_running = false;
		}
		if (ImGui::Button("Go to Game"))
		{
			SceneManager::Run(1);
		}
		
		ImGui::End();
	}
}

void MainMenu::render()
{
	///m_window->draw(*m_backgroundSprite);

	for (size_t i = 0; i < MAIN_MENU_ARRAY_SIZE; i++)
	{
		m_window->draw(menuText[i]);
	}
}

void MainMenu::cleanup()
{

}
