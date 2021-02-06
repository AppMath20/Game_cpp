#ifndef RANDOM_BONUS_H
#define RANDOM_BONUS_H
#include <memory>
#include "VirtualField.h"

class RandomBonus
{
protected:
	unsigned m_positionX;
	unsigned m_positionY;
	unsigned m_Kind;

public:

	RandomBonus(unsigned posX, unsigned posY, unsigned kind);

	virtual unsigned ResearchVirtualField(std::shared_ptr <VirtualField> VirtualField) = 0;
	unsigned GetPositionX();
	unsigned GetPositionY();
	unsigned GetKindRandomBonus();

	~RandomBonus() {};
};

#endif