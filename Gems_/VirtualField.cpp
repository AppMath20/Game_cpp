#include <string>
#include <cstdlib>
#include "VirtualField.h"
#include "Constants.h"
#include <memory>
#include <array>
#include <vector>

VirtualField::VirtualField()
{
	GeneratingVirtualField();
}

void VirtualField::GeneratingVirtualField() //Заполнение поля камней
{
	for (unsigned i = 0; i < NUMBER_IN_COlUMN; i++)
	{
		std::vector <Gem> temp;

		for (unsigned j = 0; j < NUMBER_IN_ROW; j++)
			temp.push_back({ m_ColorsVector[rand() % NUMBER_COLORS] });

		m_TableGems.push_back(temp);
		temp.~vector();
	}
}

unsigned VirtualField::DeletingGems()
{
	m_Recurrence.clear();

	for (unsigned i = 0; i < NUMBER_IN_COlUMN; i++)
	{
		for (unsigned j = 0; j < NUMBER_IN_ROW; j++)
		{
			m_Recurrence.push_back({ i, j });
			FindSequence(i, j);

			if (m_Recurrence.size() > 2)
				break;
			else m_Recurrence.clear();
		}
		if (m_Recurrence.size() > 2)
			break;
	}
	for (unsigned k = 0; k < m_Recurrence.size(); k++)
	{
		m_TableGems[m_Recurrence[k][0]][m_Recurrence[k][1]].SetEmpty();
	}
	return (unsigned)m_Recurrence.size();
}

bool VirtualField::IsPossibleToPutSequence(unsigned i1, unsigned j1, unsigned i2, unsigned j2) //Дает оценку на проверку сосоедних камней
{
	bool IsColor = false, IsChoosed = true;

	if (m_TableGems[i1][j1].GetColor() == m_TableGems[i2][j2].GetColor())
		IsColor = true;

	for (unsigned k = 0; k < m_Recurrence.size(); k++)
		if ((i2 == m_Recurrence[k][0]) && (j2 == m_Recurrence[k][1]))
			IsChoosed = false;

	return (IsColor && IsChoosed);
}

void VirtualField::FindSequence(unsigned i, unsigned j)
{
	if ((i != 0) && (IsPossibleToPutSequence(i, j, i - 1, j))) //верхний камень
	{
		m_Recurrence.push_back({ i - 1, j });
		FindSequence(i - 1, j);
	}
	else if ((j != NUMBER_IN_ROW - 1) && (IsPossibleToPutSequence(i, j, i, j + 1)))//правый
	{
		m_Recurrence.push_back({ i, j + 1 });
		FindSequence(i, j + 1);
	}
	else if ((i != NUMBER_IN_COlUMN - 1) && (IsPossibleToPutSequence(i, j, i + 1, j)))//нижний
	{
		m_Recurrence.push_back({ i + 1, j });
		FindSequence(i + 1, j);
	}
	else if ((j != 0) && (IsPossibleToPutSequence(i, j, i, j - 1)))//левый
	{
		m_Recurrence.push_back({ i, j - 1 });
		FindSequence(i, j - 1);
	}
}

void VirtualField::RecoveryVirtualField()
{
	for (unsigned i = 0; i < NUMBER_IN_COlUMN; i++)
	{
		for (unsigned j = 0; j < NUMBER_IN_ROW; j++)
		{
			if (m_TableGems[i][j].IsEmpty())
			{
				m_TableGems[i][j].SetColor(m_ColorsVector[(rand() % NUMBER_COLORS)]);
			}
		}
	}
}

bool VirtualField::isSlump()
{
	bool Slump = false;

	for (unsigned i = 0; i < NUMBER_IN_COlUMN - 1; i++)
	{
		for (unsigned j = 0; j < NUMBER_IN_ROW; j++)
		{
			Slump = IsChangePositionGem(i, j);
		}
	}
	return Slump;
}


void VirtualField::SwapCoordinate(unsigned posX1, unsigned posY1, unsigned posX2, unsigned posY2)
{
	sf::Color color1, color2;
	color1 = m_TableGems[posY1][posX1].GetColor();
	color2 = m_TableGems[posY2][posX2].GetColor();

	m_TableGems[posY1][posX1].SetColor(color2);
	m_TableGems[posY2][posX2].SetColor(color1);

}

bool VirtualField::IsChangePositionGem(unsigned posX, unsigned posY)
{
	if ((!m_TableGems[posX][posY].IsEmpty()) && (m_TableGems[posX + 1][posY].IsEmpty()))
	{
		m_TableGems[posX + 1][posY].SetColor(m_TableGems[posX][posY].GetColor());
		m_TableGems[posX][posY].SetEmpty();
		return true;
	}
}

std::vector<std::vector<Gem>> VirtualField::GetTableGems()
{
	return m_TableGems;
}

bool VirtualField::GemIsEmpty(unsigned i, unsigned j)
{
	return m_TableGems[i][j].IsEmpty();
}

std::vector <std::array <unsigned, 2>> VirtualField::GetRecurrenceVector()
{
	return m_Recurrence;
}

