#include "ship.h"
#include <iostream>
#include <string>

ship::ship(int x, int y) { 
	xsize = x;
	ysize = y;
	map = new std::string * [xsize];
	for (x = 0; x < xsize; x++) {
		map[x] = new std::string[ysize];

	}

	gen_blank_map();
}

ship::~ship() {
	for (int x = 0; x < xsize; x++) {
		delete [] map[x];
	}
	delete [] map;
}

void ship::gen_blank_map() {//resets the entire map
	for (int i = 0; i < xsize; i++) {
		for (int y = 0; y < ysize; y++) {
			map[i][y] = "0";
		}
		
	}

}


void ship::fillspace() {// fills the entire map with rooms


}


void ship::print() {

	for (int i = 0; i < xsize; i++) {
		for (int y = 0; y < ysize; y++) {
			std::cout << map[i][y];
		}
		std::cout<< std::endl;
	}

}