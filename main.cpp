#include <iostream>
#include <stdlib.h>
#include "ship.h"

void printKey() {
	std::cout << ". = space in the room" << std::endl;
	std::cout << ", = corner" << std::endl;
	std::cout << "d = door/hidden door" << std::endl;
	std::cout << "| = wall " << std::endl;
	std::cout << "_ = wall" << std::endl;
	std::cout << "H = hallway" << std::endl;
	std::cout << "s stair case to floor right above or below" << std::endl;

}

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
	int floorcount;
	int input = -1;

	ship *s;

	while (running) {

		switch (input)
		{
		case 1:
			std::cout << "input max width, then max height" << std::endl;
			std::cin >> xsize;
			std::cin >> ysize;
			std::cout << "how many floors do you want" << std::endl;
			std::cin >> floorcount;
			if (floorcount <= 0) {
				floorcount = 1;
			}
			s =new ship(xsize, ysize, floorcount);
			//std::cout << "filling space" << std::endl;
			s->fillspace();
			//std::cout << "merging rooms" << std::endl;
			s->mergerooms();
			//std::cout << "generating hallways" << std::endl;
			s->generateHallways();
			//std::cout << "printing" << std::endl;
			s->print();
			printKey();
		//	s->detectRoom();
			delete s;
			break;
		case 2:
		
			break;
		case 3:
			
			break;
		case 4:
			std::cout << "input max width, then max height" << std::endl;
			std::cin >> xsize;
			std::cin >> ysize;
			std::cout << "how many floors do you want" << std::endl;
			std::cin >> floorcount;
			if (floorcount <= 0) {
				floorcount = 1;
			}
			s = new ship(xsize, ysize, floorcount, true);
			s->grid_hallways();
			s->grid_fillspace();
			s->print();

			delete s;
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
			running = false;
			break;
		case 13:
			break;

		default:
			std::cout << "that is not an option" << std::endl;
			break;
		}
		if (running) {
			std::cin >> input;
			drawmenu();
		}
	}


	return 0;
}