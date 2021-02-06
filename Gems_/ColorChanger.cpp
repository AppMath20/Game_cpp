#include <iostream>
#include "ColorChanger.h"


unsigned —olor—hanger::ResearchVirtualField(std::shared_ptr < VirtualField> VirtualField)
{
	std::vector <std::array<unsigned, 2>> renderedGems;
	unsigned X, Y;
	bool Sum, IsEmpty = false, IsChoose = false;

	for (unsigned i = 0; i < NUMBER_CHANGE_GEM; i++)
	{
		do
		{
			X = m_positionX + (unsigned)(rand() % 3)* (unsigned)pow(-1, rand() % 2);
			Y = m_positionY + (unsigned)(rand() % 3)* (unsigned)pow(-1, rand() % 2);

			if ((X < NUMBER_IN_ROW) & (Y < NUMBER_IN_COlUMN))
			{

				IsChoose = IsAlreadyInVector(X, Y, renderedGems);

				IsEmpty = VirtualField->GemIsEmpty(X, Y);

				Sum = IsEmpty || IsChoose;
			}
			else Sum = true;

		} while (Sum);

		renderedGems.push_back({ X, Y });
	}

	RenderGems(VirtualField,m_positionX, m_positionY, renderedGems);

	return 0;
}

void —olor—hanger::RenderGems(std::shared_ptr <VirtualField> VirtualField, unsigned posX, unsigned posY, const std::vector <std::array<unsigned, 2>> &renderedGems)//
{
	for (unsigned k = 0; k < renderedGems.size(); k++)
		VirtualField->GetTableGems()[renderedGems[k][0]][renderedGems[k][1]].SetColor(VirtualField->GetTableGems()[posX][posY].GetColor());
}

bool —olor—hanger::IsAlreadyInVector(unsigned i, unsigned j, const std::vector <std::array <unsigned, 2>> &checkVector)
{
	for (unsigned k = 0; k < checkVector.size(); k++)
		if ((i == checkVector[k][0]) && (j == checkVector[k][1]))
			return true;
	return false;
}