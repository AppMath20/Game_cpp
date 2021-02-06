#ifndef COLOR_H
#define COLOR_H
#include <memory>
#include "RandomBonus.h"

class —olor—hanger :public RandomBonus
{

public:
	—olor—hanger(unsigned posX, unsigned  posY, unsigned kind) :RandomBonus(posX, posY, 1) {}

	unsigned ResearchVirtualField(std::shared_ptr <VirtualField> VirtualField);
	bool IsAlreadyInVector(unsigned i, unsigned j, const std::vector <std::array <unsigned, 2>> &checkVector);
	void RenderGems(std::shared_ptr <VirtualField> VirtualField, unsigned posX, unsigned posY, const std::vector <std::array<unsigned, 2>> &renderedGems);

	~—olor—hanger() {};
};
#endif