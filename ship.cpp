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
	//std::cout << "rooms generated: " << roomsgenerated << std::endl;
}


void ship::mergerooms() {
	std::cout<<"merging rooms" << std::endl;

	for (int y = 0; y < ysize; y++) {
		for (int x = 0; x < ysize; x++) {
			
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
			}else
			if (map[y][x] == ","  &&y > 0 && y < ysize) {
				if (map[y + 1][x] == "|" && map[y - 1][x] == "|") {
					map[y][x] = "|";
					//std::cout << "merging " << map[y][x] << " @ " << x << "," << y << std::endl;
				}
			}
			else if (map[y][x] == ","&&x > 0 && x < xsize) {
				if (map[y][x + 1] == "_"&&map[y][x - 1] == "_") {

					map[y][x] = "_";
					//std::cout << "merging "<< map[y][x ]<<" @ "<<x<<","<<y << std::endl;
				}
			}else
				if (map[y][x] == "d") {//removes doors
				if (y == 0 || y==ysize-1) {// if the door is located on the left/right side of the map
					map[y][x] = "_";
					
				}
				else if (x == 0 || x == xsize - 1) {//if the door is located ont the top/bottom of the map
					map[y][x] = "|";
					
				}
				else if ((map[y][x+1]=="."&&map[y][x-1]==".") || (map[y+1][x]=="."&&map[y-1][x]==".")) {
					map[y][x] = ".";
					
				}
				else {
					//only add doors that have areas to connect to other doors/hallways
					if (map[y - 1][x] == " " || map[y][x + 1] == " " || map[y + 1][x] == " " || map[y][x - 1] == " ") {
						dcor temp;
						temp.x = x;
						temp.y = y;

						rmdoors.push_back(temp);
					}
				}

			}

		}

	}
	//map[0][0] = "a";
	//std::cout << "rooms found: " << roomsfound << std::endl;
}

void ship::generateHallways() {
	bool connecting;
	int x;
	int y;
	bool n;
	bool e;
	bool s;
	bool w;
	bool scouting;
	bool lredge;
	bool tdedge;
	for (int i = 0; i < rmdoors.size(); i++) {// run through all of the doors
		connecting = true;
		x = rmdoors[i].x;
		y = rmdoors[i].y;
		

			//chcking to see if it is connected to the hallway
			if (map[y][x + 1] != "H"  && map[y + 1][x] != "H"
				&& map[y][x - 1] != "H" && map[y - 1][x] != "H") {

				//check to see were to place the hallway
				n = false;
				e = false;
				s = false;
				w = false;
				tdedge = false;
				lredge = false;
				if (map[y - 1][x] == " ") {//picks the starting direction
					n = true;
				}
				else if (map[y][x + 1] == " ") {
					e = true;
				}
				else if (map[y + 1][x] == " ") {
					s = true;
				}
				else if (map[y][x - 1] == " ") {
					w = true;
				}

				 scouting = true;

				while (connecting) {// connecting it to to the hallway/another door only moving one block per cycle
				
					if (scouting) {//moving streight untill it hits a wall/object
						if (n) {//going north
							y--;
							if (y >= 0) {
								if (map[y][x] == " ") {//if it is empty then add a hallway
									map[y][x] = "H";

									//check to see if the soundings are a door/hallway

									if (y - 1 >= 0 && y+1<ysize) {
										if (map[y - 1][x] == "H" || map[y][x - 1] == "H" || map[y - 1][x] == "d" || map[y][x - 1] == "d") {
											scouting = false;
											connecting = false;
										}
									}

									if (x - 1 >= 0 && x+1 < xsize) {
										if (map[y][x + 1] == "H" || map[y][x + 1] == "d") {
											scouting = false;
											connecting = false;
										}
									}
																		
									
								}
								else if (map[y][x] == "_" || map[y][x] == "|") {
									map[y][x] = "d";
									scouting = false;
									connecting = false;
								}
								else {//if not then the it will trace the room
								
									scouting = false;
									y++;
									connecting = false;

								}
							}
							else {
								scouting = false;
								tdedge = true;
								y++;
								connecting = false;

							}
						}
						else if (e) {//going east
							x++;
							if (x < xsize) {
								if (map[y][x] == " ") {//if it is empty then add a hallway
									map[y][x] = "H";

									//check to see if the soundings are a door/hallway

									if (y - 1 >= 0 && y + 1 < ysize) {
										if ((map[y - 1][x] == "H" || map[y + 1][x] == "H") ||
											(map[y - 1][x] == "d" || map[y + 1][x] == "d")) {
											scouting = false;
											connecting = false;
										}
									}
									if (x - 1 >= 0 && x + 1 < xsize) {
										if (map[y][x + 1] == "H" || map[y][x + 1] == "d") {
											scouting = false;
											connecting = false;
										}
									}
									

								}
								else if (map[y][x] == "_" || map[y][x] == "|") {
									map[y][x] = "d";
									scouting = false;
									connecting = false;
								}
								else {//if not then the it will trace the room
									scouting = false;
									x--;
									connecting = false;
								}
							}
							else {
								scouting = false;
								lredge = true;
								x--;
								connecting = false;
							}

						}
						else if (s) {//going south
							y++;
							if (y < ysize) {
								if (map[y][x] == " ") {//if it is empty then add a hallway
									map[y][x] = "H";

									//check to see if the soundings are a door/hallway

									if (y - 1 >= 0 && y + 1 < ysize) {
										if (map[y + 1][x] == "H" || map[y + 1][x] == "d") {
											scouting = false;
											connecting = false;
										}
									}

									if (x - 1 >= 0 && x + 1 < xsize) {
										if ((map[y][x + 1] == "H" || map[y][x - 1] == "H") ||
											(map[y][x + 1] == "d" || map[y][x - 1] == "d")) {
											scouting = false;
											connecting = false;
										}
									}
									

								}
								else if (map[y][x] == "_" || map[y][x] == "|") {
									map[y][x] = "d";
									scouting = false;
									connecting = false;
								}
								else {//if not then the it will trace the room
									scouting = false;
									y--;
									connecting = false;
								}
							}
							else {
								scouting = false;
								tdedge = true;
								y--;
								connecting = false;
							}
						}
						else if (w) {//going west
							x--;
							if (x >= 0) {
								if (map[y][x] == " ") {//if it is empty then add a hallway
									map[y][x] = "H";
									//check to see if the soundings are a door/hallway
									if (y - 1 >= 0 && y + 1 < ysize) {
										if (map[y + 1][x] == "H" || map[y + 1][x] == "d"|| map[y - 1][x] == "H" || map[y - 1][x] == "d") {
											scouting = false;
											connecting = false;
										}
									}

									if (x - 1 >= 0 && x + 1 < xsize) {
										if ((map[y][x - 1] == "H") || map[y][x - 1] == "d") {
											scouting = false;
											connecting = false;
										}
									}
									
								}
								else if (map[y][x] == "_" || map[y][x] == "|") {
									map[y][x] = "d";
									scouting = false;
									connecting = false;
								}
								else {//if not then the it will trace the room
									scouting = false;
									x++;
									connecting = false;
								}
							}
							else {
								scouting = false;
								lredge = true;
								x++;
								connecting = false;
							}
						}
						
					}
					else {//traces the object that it 
					if (lredge) {//if the hallwalys run into the edge


						}else
					if (tdedge) {//if the hallwalys run into the edge


					}
						//map[y][x] = "H";
						/*if ((map[y - 1][x] == "d" || map[y][x + 1] == "d" || map[y + 1][x] == "d" || map[y][x - 1] == "d") ||//checks for doors
							(map[y - 1][x] == "H" || map[y][x + 1] == "H" || map[y + 1][x] == "H" || map[y][x - 1] == "H")) {//checks for hallways
							connecting = false;
						}*/
					}
					

						
				}
			}
		
	}
	
}

void ship::fillrooms() {


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