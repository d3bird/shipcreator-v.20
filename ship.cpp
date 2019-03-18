#include "ship.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

ship::ship(int x, int y) { 
	xsize = x;
	ysize = y;

	minrs = 3;
	maxrs = 4;

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
	srand(time(NULL));
	
	int xloc = 0;
	int yloc = 0;
	bool creating = true;
	int rmsize;// = rand() % maxrs + minrs;
	while (creating) {// the loop for creating rooms till no more wll fit
		rmsize = rand() % maxrs + minrs;//generates the size of the room
		
		if ((yloc + rmsize) >= ysize) {// at the very bottom and neets to move to the next row
			xloc += 5;
			if (xloc >= xsize) {// if the x axis runs out then it moves to the next x pos
				creating = false;
				std::cout << "ran out of space" << std::endl;
			}
			
		}
		else {//there should be room to gen the room

			for (int x = 0; x < rmsize; x++) {
				for (int y = 0; y < rmsize; y++) {
					if ((y == 0 && x == 0) || (y == 0 && x == rmsize - 1) || (y == rmsize - 1 && x == 0) || (y == rmsize - 1 && x == rmsize - 1) ){
						map[x][y] = ",";
					}else if (y == 0 || y == rmsize-1){
						map[x][y] = "|";
					}
					else if (x == 0 || x == rmsize - 1) {
						map[x][y] = "_";
					}
					else {
						map[x][y] = ".";
					}
	

				}
			}

		}




	}
}


void ship::print() {

	for (int i = 0; i < xsize; i++) {
		for (int y = 0; y < ysize; y++) {
			std::cout << map[i][y];
		}
		std::cout<< std::endl;
	}

}