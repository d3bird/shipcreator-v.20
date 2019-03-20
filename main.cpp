#include <iostream>
#include "ship.h"
#include <iostream>


int main() {
	ship s(100, 100);


	s.fillspace();
	//s.print();
	s.mergerooms();
	s.generateHallways();
	s.print();
	//s.debugprint();

	std::cin.get();

	return 0;
}