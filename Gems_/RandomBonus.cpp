#include <iostream>
#include "RandomBonus.h"


RandomBonus::RandomBonus(unsigned x, unsigned y, unsigned kind)
{
	m_positionX = x;
	m_positionY = y;
	m_Kind = kind;
}

unsigned RandomBonus::GetPositionX()
{
	return m_positionX;
}

unsigned RandomBonus::GetPositionY()
{
	return m_positionY;
}

unsigned RandomBonus::GetKindRandomBonus()
{
	return m_Kind;
}
