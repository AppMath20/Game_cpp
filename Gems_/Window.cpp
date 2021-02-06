#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "Constants.h"
#include "Window.h"

Window::Window(unsigned width, unsigned height, std::string title)
{
	m_Point = 0;
	m_positionX1 = 0;
	m_positionX2 = 0;
	m_positionY1 = 0;
	m_positionY2 = 0;
	m_Background = sf::Color::White;
	m_isSlump = false;
	m_isSwap = false;
	
	m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(height, width), title);
	m_Window->setFramerateLimit(10);
	m_VirtualField = std::make_shared<VirtualField>();
}

void Window::ClickMouse()//
{
	if (m_click == 1)
	{
		m_positionX1 = (unsigned)((m_position.x) / GEM_HEIGHT);
		m_positionY1 = (unsigned)((m_position.y) / GEM_WIDTH);

	}
	else if (m_click == 2)
	{
		m_positionX2 = (unsigned)((m_position.x) / GEM_HEIGHT);
		m_positionY2 = (unsigned)((m_position.y) / GEM_WIDTH);

		if (IsExchangePossible(m_positionX1, m_positionY1, m_positionX2, m_positionY2))
		{
			m_isSwap = true;
			m_click = 0;
		}
		else m_click = 1;
	}
}

bool Window::IsExchangePossible(unsigned posX1, unsigned posY1, unsigned posX2, unsigned posY2)
{
	bool Distance = false;
	bool Adjacency = false;

	if (((std::abs((int)(posX2 - posX1))) <= 1) && (std::abs((int)(posY2 - posY1) <= 1)))
		Distance = true;

	if (((!(std::abs((int)(posX2 - posX1))) == 1) && ((std::abs((int)(posY2 - posY1))) == 1))
		|| (((std::abs((int)(posX2 - posX1))) == 1) && (!(std::abs((int)(posY2 - posY1))) == 1)))
		Adjacency = true;

	return (Distance & Adjacency);
}

void Window::PermutationGems()
{
	if (m_isSwap && (m_isSlump == false))
	{
		m_VirtualField->SwapCoordinate(m_positionX1, m_positionY1, m_positionX2, m_positionY2);
		m_isSwap = false;
	}
}

void Window::DeleteGems()
{
	if (m_isSlump == false)
	{
		m_Point += m_VirtualField->DeletingGems();
	}
}
	
void Window::AppeareanceRandomBonus()
{
	if (m_VectorRandomBonus.size() > 0)
	{
		for (unsigned k = 0; k < m_VectorRandomBonus.size(); k++)
		{
			m_Point += m_VectorRandomBonus[k]->ResearchVirtualField(m_VirtualField);
		}
		m_VectorRandomBonus.clear();
	}
}

void Window::SlumpGems()
{
	m_isSlump = m_VirtualField->isSlump();
}

void Window::CompletionVirtualField()
{
	if (m_isSlump == false)
	{
		m_VirtualField->RecoveryVirtualField();

		NoteRandomBonusOnGem();

	}
}

void Window::NoteRandomBonusOnGem() 
{
	unsigned X, Y,random;
	for (unsigned k = 0; k < (m_VirtualField->GetRecurrenceVector()).size(); k++)
		if (rand() % 200 < 20)
		{
			do
			{
				X = m_VirtualField->GetRecurrenceVector()[k][1] + ((rand() % RADIUS_GEM)+1) * (unsigned)pow(-1, rand() % 2);
				Y = m_VirtualField->GetRecurrenceVector()[k][0] + ((rand() % RADIUS_GEM)+1) * (unsigned)pow(-1, rand() % 2);

			} while ((X >= NUMBER_IN_ROW) || (Y >= NUMBER_IN_COlUMN));

			random = rand() % 2;
			if (random == 0) {
				m_VectorRandomBonus.push_back(std::make_unique<Bomb>(X, Y, 0));
				break;
			}
			else if(random  == 1){
				m_VectorRandomBonus.push_back(std::make_unique<ÑolorÑhanger>(X, Y, 1));
				break;
			}
		}

}

void Window::DrawVirtualField()
{
	float posX, posY;
	sf::Color Color;

	for (unsigned i = 0; i < NUMBER_IN_COlUMN; i++)
		for (unsigned j = 0; j < NUMBER_IN_ROW; j++)
		{
			posX = i * GEM_HEIGHT;
			posY = j * GEM_WIDTH;
			Color = m_VirtualField->GetTableGems()[j][i].GetColor();

			DrawGem(posX, posY, Color);
		}
}

void Window::DrawGem(unsigned posX, unsigned posY, sf::Color color)
{
	sf::RectangleShape shape(sf::Vector2f(GEM_HEIGHT, GEM_HEIGHT));
	shape.setFillColor(color);
	shape.setPosition(posX, posY);
	shape.setOutlineThickness(-8);

	m_Window->draw(shape);
}

void Window::DrawRandomBonus()
{
	unsigned posX, posY, kind;
	sf::Color Color;
	for (unsigned k = 0; k < m_VectorRandomBonus.size(); k++)
	{
		posX = m_VectorRandomBonus[k]->GetPositionX();
		posY = m_VectorRandomBonus[k]->GetPositionY();
		kind = m_VectorRandomBonus[k]->GetKindRandomBonus();

		sf::RectangleShape shape(sf::Vector2f(GEM_WIDTH, GEM_HEIGHT));
		shape.setPosition(posX * GEM_HEIGHT, posY * GEM_WIDTH);
		shape.setOutlineThickness(-18);
		if(kind == 0)
		shape.setOutlineColor(sf::Color::Black);
		else
		shape.setOutlineColor(sf::Color::Red);

		m_Window->draw(shape);

	}
}

void Window::SetBackground(sf::Color color)
{
	m_Window->clear(color);
	m_Background = color;
}

std::string Window::getTitle()
{
	return "Gems | Point: " + std::to_string(Window::m_Point);
}

void Window::Start() //Èãðîâîé öèêë
{
	while (m_Window->isOpen())
	{
		sf::Event event;
		while (m_Window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_Window->close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					if (!m_isSwap && !m_isSlump) m_click++;
					m_position = sf::Mouse::getPosition(*m_Window);
				}
			}
		}

		m_Window->clear(m_Background);

		
		DeleteGems();
		AppeareanceRandomBonus();
		SlumpGems();
		CompletionVirtualField();
		ClickMouse();
		PermutationGems();
		DrawVirtualField();
		DrawRandomBonus();

		m_Window->display();

		m_Window->setTitle(Window::getTitle());

		if (m_Point >= 250)
		{
			m_Window->close();
		}
	}
}