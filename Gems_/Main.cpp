#include"Window.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>


unsigned main()
{
	srand(time(NULL));

	Window Window(500, 500, "Gems");
	Window.SetBackground(sf::Color::White);
	Window.Start();

	return 0;
}