#include "Gem.h"

Gem::Gem(sf::Color Color)
{
	m_Color = Color;

}

bool Gem::IsEmpty()
{
	if (m_Color == sf::Color::White)
		return true;
	return false;
}

void Gem::SetEmpty()
{
	m_Color = sf::Color::White;
}

sf::Color Gem::GetColor()
{
	return m_Color;
}

void Gem::SetColor(sf::Color Color)
{
	m_Color = Color;
}