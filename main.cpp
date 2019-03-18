#include <iostream>
#include "ship.h"
#include <iostream>


int main() {
	ship s(20, 20);


	s.fillspace();
	s.print();


	std::cin.get();

	return 0;
}