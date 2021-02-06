#include <iostream>
#include "Bomb.h"

unsigned Bomb::ResearchVirtualField(std::shared_ptr <VirtualField> VirtualField)
{
	std::vector <std::array<unsigned, 2>> detonatedGems;

	for (unsigned i = 0; i < NUMBER_BOMB - 1; i++)
	{
		detonatedGems.push_back({ rand() % NUMBER_IN_COlUMN, rand() % NUMBER_IN_ROW });
	}

	detonatedGems.push_back({ m_positionX, m_positionY });

	DetonateGem(VirtualField, detonatedGems);
	
	return detonatedGems.size();

	detonatedGems.clear();
}

void Bomb::DetonateGem(std::shared_ptr <VirtualField> VirtualField,const std::vector <std::array<unsigned, 2>> &detonatedGems)
{ 
	for (unsigned k = 0; k < detonatedGems.size(); k++)
	{
		VirtualField->GetTableGems()[detonatedGems[k][0]][detonatedGems[k][1]].SetEmpty();
	}
}