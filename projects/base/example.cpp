#include "example.h"


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

	m_catSprite = kage::TextureManager::getSprite("data/cat.png");
	m_catTexture = kage::TextureManager::getTexture("data/cat.png");

	
	
	//sf::Vector2u resolution = m_catSprite->getTexture()->getSize();
	//m_catSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);


	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	for (size_t i = 0; i < CELL_COUNT_Y; i++)
	{
		line[i] = sf::RectangleShape(sf::Vector2f(5, CELL_COUNT_Y * CELL_HEIGHT));
		line[i].setPosition(sf::Vector2f(GRID_OFFSET_X + i *CELL_HEIGHT, GRID_OFFSET_Y));
		line[i].setFillColor(sf::Color::Red);
	}
	for (size_t i = 0; i < CELL_COUNT_X; i++)
	{
		linehorizontal[i] = sf::RectangleShape(sf::Vector2f(CELL_COUNT_X * CELL_WIDTH, 5));
		linehorizontal[i].setPosition(sf::Vector2f(GRID_OFFSET_X, GRID_OFFSET_Y + i * CELL_WIDTH ));
		linehorizontal[i].setFillColor(sf::Color::Green);
	}
	for (size_t y = 0; y < CELL_COUNT_Y; y++)
	{
		for (size_t x = 0; x < CELL_COUNT_X; x++)
		{
			tiles[x + y * CELL_COUNT_X].setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));
		}
	}
	
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
		std::cout << " x " << x << " y " << y << std::endl;


		tiles[x + y * CELL_COUNT_X].setTexture(*m_catTexture);
	}


	//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;

	m_catSprite->setPosition(mousePosition);

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
{
	
	//m_window.draw(*m_backgroundSprite);
	m_window.draw(*m_catSprite);
	
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
	delete m_catSprite;
}



