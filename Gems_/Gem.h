#ifndef GEM_H
#define GEM_H
#include <SFML/Graphics.hpp>
#include "Constants.h"

class Gem
{
	sf::Color m_Color;

public:

	Gem(sf::Color Color);

	bool IsEmpty();
	void SetEmpty();
	void SetColor(sf::Color Color);
	sf::Color GetColor();

	~Gem() {};
};
#endif