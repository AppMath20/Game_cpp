#ifndef WINDOW_H
#define WINDOW_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<memory>
#include<array>
#include"VirtualField.h"
#include"RandomBonus.h"
#include"Bomb.h"
#include"ColorChanger.h"
#include"Constants.h"

class Window
{
	sf::Vector2i m_position;
	sf::Color m_Background;

	unsigned m_Point;
	unsigned m_positionX1;
	unsigned m_positionX2;
	unsigned m_positionY1;
	unsigned m_positionY2;
	unsigned m_click;

	bool m_isSlump;
	bool m_isSwap;
	
	std::unique_ptr <sf::RenderWindow> m_Window;
	std::shared_ptr <VirtualField> m_VirtualField;
	std::vector<std::unique_ptr<RandomBonus>> m_VectorRandomBonus;

public:
	Window(unsigned width, unsigned height, std::string title);

	void Start();
	void NoteRandomBonusOnGem();
	void AppeareanceRandomBonus();
	void DeleteGems();
	void PermutationGems();
	void SlumpGems();
	void CompletionVirtualField();
	void ClickMouse();
	void DrawVirtualField();
	void DrawRandomBonus();
	void DrawGem(unsigned posX, unsigned posY, sf::Color color);

	void SetBackground(sf::Color color);
	std::string getTitle();
	bool IsExchangePossible(unsigned posX1, unsigned posY1, unsigned posX2, unsigned posY2);

	~Window() {};
};
#endif //  

