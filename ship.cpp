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
			map[i][y] = " ";
		}
		
	}

}


void ship::fillspace() {// fills the entire map with rooms
	srand(time(NULL));
	int roomsgenerated = 0;
	int xloc = 0;
	int yloc = 0;
	bool creating = true;
	int rmsize;// = rand() % maxrs + minrs;
	
	int doors;
	int lastrow = -1;
	int lastcol = -1;

	while (creating) {// the loop for creating rooms till no more wll fit
		rmsize = rand() % maxrs + minrs;//generates the size of the room
		
		if ((yloc + rmsize) >= ysize) {// at the very bottom and neets to move to the next row
			xloc += 5;
			yloc = 0;
			if (xloc >= xsize) {// if the x axis runs out then it moves to the next x pos
				creating = false;
				std::cout << "ran out of space" << std::endl;
			}
			
		}
		else if(xloc+rmsize<xsize){//there should be room to gen the room
			doors = rand() % 4;
			doors++;//makesure that rooms dont have zero doors
			int mid = rmsize / 2;// gets the middle of the room to place the doors
			for (int x = 0; x < rmsize; x++) {
				for (int y = 0; y < rmsize; y++) {
					if ((y == 0 && x == 0) || (y == 0 && x == rmsize - 1) || (y == rmsize - 1 && x == 0) || (y == rmsize - 1 && x == rmsize - 1) ){
						map[yloc + y][xloc+x] = ",";
					}else if (y == 0 || y == rmsize-1){

						if (x == mid && doors>0) {
							map[yloc + y][xloc + x] = "d";
							doors--;
							
						}
						else {
							map[yloc + y][xloc + x] = "_";
						}

					}
					else if (x == 0 || x == rmsize - 1) {

						if (y == mid && doors > 0) {
							map[yloc + y][xloc + x] = "d";
							doors--;
							
						}else {
						map[yloc + y][xloc + x] = "|";
					}
					}
					else {
						map[yloc + y][xloc + x] = ".";
					}
	

				}
			}
			roomsgenerated++;
			yloc += rmsize+2;
		}




	}
	std::cout << "rooms generated: " << roomsgenerated << std::endl;
}


bool ship::detectRoom(int x, int y) {
	bool finding = true;



	return true;
}


void ship::mergerooms() {
	std::cout<<"merging rooms" << std::endl;

	for (int x = 0; x < xsize; x++) {
		for (int y = 0; y < ysize; y++) {
			
			if (map[y][x] == "_"  &&y>0 && y<ysize) {
				if (map[y + 1][x] == "." && map[y - 1][x] == ".") {
					map[y][x] = ".";
					//std::cout << "merging " << map[y][x] << " @ " << x << "," << y << std::endl;
				}
			}
			else if (map[y][x] == "|"&&x>0&&x<xsize) {
				if (map[y][x + 1] == "."&&map[y][x - 1] == ".") {
					
					map[y][x] = ".";
					//std::cout << "merging "<< map[y][x ]<<" @ "<<x<<","<<y << std::endl;
				}
			}

			if (map[y][x] == "d") {
				if (y == 0 || y==ysize-1) {// if the door is located on the left/right side of the map
					map[y][x] = "_";
				}
				else if (x == 0 || x == xsize - 1) {//if the door is located ont the top/bottom of the map
					map[y][x] = "|";
				}
				else if ((map[y][x+1]=="."&&map[y][x-1]==".") || (map[y+1][x]=="."&&map[y-1][x]==".")) {
					map[y][x] = ".";
				}

			}

		}

	}
	//map[0][0] = "a";
	//std::cout << "rooms found: " << roomsfound << std::endl;
}

void ship::debugprint() {

	for (int i = -1; i < xsize; i++) {
		for (int y = -1; y < ysize; y++) {
			if (i == -1) {
				std::cout << y + 1;
			}
			else if (y == -1) {
				if (i < 10) {
					std::cout << i<<" ";
				}
				else {
					std::cout << i;
				}
			}
			else {
				std::cout << map[i][y];
			}
		}
		std::cout << std::endl;
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