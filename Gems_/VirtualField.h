#ifndef VIRTUAL_FIELD_H
#define VIRTUAL_FIELD_H
#include "Gem.h"
#include <memory>
#include <array>
#include <vector>
#include "Constants.h"


class VirtualField
{
	std::vector <std::vector <Gem>> m_TableGems;
	sf::Color m_ColorsVector[NUMBER_COLORS] = { sf::Color(100,250,150), sf::Color(250,150,100), sf::Color(100,100,0), sf::Color(150,100,100) ,sf::Color(200,0,100)};
	std::vector <std::array <unsigned, 2>> m_Recurrence;

public:

	VirtualField();

	void GeneratingVirtualField();
	void RecoveryVirtualField();
	unsigned DeletingGems();
	bool IsChangePositionGem(unsigned posX,unsigned posY);
	void FindSequence(unsigned i, unsigned j);
	bool IsPossibleToPutSequence(unsigned i1, unsigned j1, unsigned i2, unsigned j2);
	void SwapCoordinate(unsigned posX1, unsigned posY1, unsigned posX2, unsigned posY2);

	bool isSlump();
	bool GemIsEmpty(unsigned i, unsigned j);
	std::vector<std::vector<Gem>> GetTableGems();
	std::vector <std::array <unsigned, 2>> GetRecurrenceVector();

	~VirtualField() {};
};
#endif
