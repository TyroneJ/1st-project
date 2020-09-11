#include "example.h"
#include <iostream>
#include <fstream>

using namespace std;

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	grass.id = 1;
	grass.m_texture = kage::TextureManager::getTexture("data/grass.png");

	rock.id = 2;
	rock.m_texture = kage::TextureManager::getTexture("data/smallrock.png");

	water.id = 3;
	water.m_texture = kage::TextureManager::getTexture("data/water.png");


	currentPressedTile = grass.id, rock.id, water.id;

	//sf::Vector2u resolution = m_catSprite->getTexture()->getSize();
	//m_catSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	//m_currentTile.setTexture(*m_grassTexture);

	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	for (size_t i = 0; i < CELL_COUNT_Y; i++)
	{
		line[i] = sf::RectangleShape(sf::Vector2f(5, CELL_COUNT_Y * CELL_HEIGHT));
		line[i].setPosition(sf::Vector2f(GRID_OFFSET_X + i * CELL_HEIGHT, GRID_OFFSET_Y));
		line[i].setFillColor(sf::Color::Red);
	}
	for (size_t i = 0; i < CELL_COUNT_X; i++)
	{
		linehorizontal[i] = sf::RectangleShape(sf::Vector2f(CELL_COUNT_X * CELL_WIDTH, 5));
		linehorizontal[i].setPosition(sf::Vector2f(GRID_OFFSET_X, GRID_OFFSET_Y + i * CELL_WIDTH));
		linehorizontal[i].setFillColor(sf::Color::Green);
	}
	for (size_t y = 0; y < CELL_COUNT_Y; y++)
	{
		for (size_t x = 0; x < CELL_COUNT_X; x++)
		{
			tiles[x + y * CELL_COUNT_X].setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));
		}
	}
	for (size_t i = 1; i < CELL_TOTAL_COUNT; i++)
	{

		switch (mapFromFile[i])
		{
		
		case 1:
			tiles[i].setTexture(*grass.m_texture);
			break;

		case 2:
			tiles[i].setTexture(*rock.m_texture);
			break;

		case 3:
			tiles[i].setTexture(*water.m_texture);
			break;

		default:
			break;

		}
	}





	// basic file operations, saving
	

		


	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	sf::Vector2f mousePosition = (sf::Vector2f)sf::Mouse::getPosition(m_window);
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		int x =  mousePosition.x / CELL_WIDTH;
		int y = mousePosition.y / CELL_HEIGHT;
		//std::cout << " x " << x << " y " << y << std::endl;
		int i = CELL_TOTAL_COUNT;

		if (x >= 0 && x < CELL_COUNT_X)
		{
			if (y >= 0 && y < CELL_COUNT_Y)
			{
				int index = x + y * CELL_COUNT_X;

				mapFromFile[i] = currentPressedTile;
				tiles[index].setTexture(*m_currentTile.getTexture());
				std::cout << index << endl; 
			}
		}
		
	}
	ImGui::Begin("Kage2D");

	if (ImGui::Button("save"))
	{
		std::ofstream myfile;
		myfile.open("map.txt");

		for (size_t y = 0; y < CELL_COUNT_Y; y++)
		{
			for (size_t x = 0; x < CELL_COUNT_X; x++)
			{
				int i = x + y * CELL_COUNT_X;

				myfile << mapFromFile[i] << std::endl;
			}
		}
		myfile.close();

	}
	if (ImGui::Button("Load"))
	{
		std::string line;
		std::ifstream file("map.txt");
		int index = 0;

		if (file.is_open())
		{


			while (getline(file, line))
			{
				int elementOne = std::stoi(line);
				mapFromFile[index] = elementOne;

				index++;
			}
			file.close();
		}

		else
			std::cout << "Unable to open file";


		std::cout << std::endl << "MAP FROM FILE " << std::endl;
		for (size_t y = 0; y < CELL_COUNT_Y; y++)
		{
			for (size_t x = 0; x < CELL_COUNT_X; x++)
			{
				int i = x + y * CELL_COUNT_X;

				std::cout << mapFromFile[i] << ", ";
			}
			std::cout << std::endl;
		}

	}

	ImGui::End();


	

	//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;

	m_currentTile.setPosition(mousePosition);


	
	ImGui::Begin("Kage2D");
	
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	
	if (ImGui::Button("Grass"))
	{
		m_currentTile.setTexture(*grass.m_texture);
	}
	
	if (ImGui::Button("Water"))
	{
		m_currentTile.setTexture(*water.m_texture);
	}

	if (ImGui::Button("rock"))
	{
		m_currentTile.setTexture(*rock.m_texture);
	}

	
	



	ImGui::End();
}

void Example::render()
{
	
	//m_window.draw(*m_backgroundSprite);
	m_window.draw(m_currentTile);
	
	for (size_t i = 0; i < CELL_COUNT_X; i++)
	{
		m_window.draw(line[i]);
	}
	for (size_t i = 0; i < CELL_COUNT_Y; i++)
	{
		m_window.draw(linehorizontal[i]);
	}
	for (size_t i = 0; i < CELL_TOTAL_COUNT; i++)
	{
		m_window.draw(tiles[i]);
	}
	
}

void Example::cleanup()
{
	//delete m_backgroundSprite;
	//delete m_currentTile;
}



