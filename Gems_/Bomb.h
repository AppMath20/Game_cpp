#ifndef BOMB_H
#define BOMB_H
#include <memory>
#include "RandomBonus.h"

class Bomb :public RandomBonus
{

public:
	Bomb(unsigned posX, unsigned posY, unsigned kind) :RandomBonus(posX, posY, 0) {}

	unsigned ResearchVirtualField(std::shared_ptr<VirtualField> VirtualField);

	void DetonateGem(std::shared_ptr <VirtualField> VirtualField,const std::vector <std::array<unsigned, 2>> &detonatedGems);

	 ~Bomb() {};
};
#endif