#include <iostream>
#include <stdlib.h>
#include "ship.h"

void drawmenu() {
	system("cls");
	std::cout << "type in what you want to do" << std::endl;
	std::cout << "1: blank ship" << std::endl;
	std::cout << "2: ship with filled rooms (no life)" << std::endl;
	std::cout << "3: ship with filled rooms (with life)" << std::endl;
	std::cout << "4 grid ship" << std::endl;
	std::cout << "4 grid ship with filled " << std::endl;
	std::cout << "5: add room" << std::endl;
	std::cout << "6: remoce room" << std::endl;
	std::cout << "7: add life form" << std::endl;
	std::cout << "10: remove life form" << std::endl;
	std::cout << "11: settings" << std::endl;
	std::cout << "12: quit" << std::endl;
	std::cout << "13: help" << std::endl;

}

int main() {
	bool running = true;
	drawmenu();
	int xsize;
	int ysize;
	
	int input = -1;

	ship *s;

	while (running) {

		switch (input)
		{
		case 1:
			std::cout << "input max width, then max height" << std::endl;
			std::cin >> xsize;
			std::cin >> ysize;
			s =new ship(xsize, ysize);
			s->fillspace();
			s->mergerooms();
			s->generateHallways();
			s->print();
			delete s;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;

		default:
			std::cout << "that is not an option" << std::endl;
			break;
		}
		
		drawmenu();
	}


	return 0;
}