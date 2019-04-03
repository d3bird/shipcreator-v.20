#include "ship.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

ship::ship(int x, int y, int i) {
	xsize = x;
	ysize = y;
	floorcount = i;
	minrs = 3;
	maxrs = 4;
	floor.resize(i);//sets the floor size
	rmdoors.resize(i);// sets the floor size for hallways gerneration
	for (i = 0; i < floor.size(); i++) {

		floor[i] = new std::string *[xsize];
		for (x = 0; x < xsize; x++) {
			floor[i][x] = new std::string[ysize];
		}
	}
	std::cout << "generating blank map" << std::endl;
	gen_blank_map();
}

ship::~ship() {
	for (int i = 0; i < floor.size(); i++) {
		for (int x = 0; x < xsize; x++) {
			delete[] floor[i][x];
		}
		delete[] floor[i];
	}
}

void ship::gen_blank_map() {//resets the entire map
	for (int i = 0; i < floor.size(); i++) {
		for (int x = 0; x < xsize; x++) {
			for (int y = 0; y < ysize; y++) {
				floor[i][x][y] = " ";
			}

		}
	}
}




void ship::fillspace() {// fills the entire map with rooms
	srand(time(NULL));
	int stairlim = 3;
	bool free = true;
	int lasty = 0;
	for (int f = 0; f < floorcount; f++) {

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

			}// need a check to makesure that it does not overlap
			else {
				

				if (xloc + rmsize < xsize) {//there should be room to gen the room
					doors = rand() % 4;
					doors++;//makesure that rooms dont have zero doors

					int mid = rmsize / 2;// gets the middle of the room to place the doors
					for (int x = 0; x < rmsize; x++) {
						for (int y = 0; y < rmsize; y++) {

							if (floor[f][yloc + y][xloc + x] == " ") {

								if ((y == 0 && x == 0) || (y == 0 && x == rmsize - 1) || (y == rmsize - 1 && x == 0) || (y == rmsize - 1 && x == rmsize - 1)) {

									if (rmsize <= stairlim && floorcount > 1 && floorcount > f + 1) {
										floor[f][yloc + y][xloc + x] = ",";
										floor[f + 1][yloc + y][xloc + x] = ",";
									}
									else {
										floor[f][yloc + y][xloc + x] = ",";
									}
								}
								else if (y == 0 || y == rmsize - 1) {

									if (x == mid && doors > 0) {
										if (rmsize <= stairlim && floorcount > 1 && floorcount > f + 1) {
											floor[f][yloc + y][xloc + x] = "d";
											floor[f + 1][yloc + y][xloc + x] = "d";
										}
										else {
											floor[f][yloc + y][xloc + x] = "d";
										}
										doors--;

									}
									else {
										if (rmsize <= stairlim && floorcount > 1 && floorcount > f + 1) {
											floor[f + 1][yloc + y][xloc + x] = "_";
											floor[f][yloc + y][xloc + x] = "_";
										}
										else {
											floor[f][yloc + y][xloc + x] = "_";
										}
									}

								}
								else if (x == 0 || x == rmsize - 1) {

									if (y == mid && doors > 0) {
										if (rmsize <= stairlim && floorcount > 1 && floorcount > f + 1) {
											floor[f + 1][yloc + y][xloc + x] = "d";
											floor[f][yloc + y][xloc + x] = "d";
										}
										else {
											floor[f][yloc + y][xloc + x] = "d";

										}
										doors--;
									}
									else {
										if (rmsize <= stairlim && floorcount > 1 && floorcount > f + 1) {
											floor[f][yloc + y][xloc + x] = "|";
											floor[f + 1][yloc + y][xloc + x] = "|";
										}
										else {
											floor[f][yloc + y][xloc + x] = "|";
										}
									}
								}
								else {
									if (rmsize <= stairlim && floorcount > 1 && floorcount > f + 1) {
										floor[f][yloc + y][xloc + x] = "s";
										floor[f + 1][yloc + y][xloc + x] = "s";
									}
									else {
										floor[f][yloc + y][xloc + x] = ".";
									}
								}

							}

						}
					}
					roomsgenerated++;
					yloc += rmsize + 2;
				}
				else {
					yloc += lasty + 2;
				}
			}



		}
	}
	//std::cout << "rooms generated: " << roomsgenerated << std::endl;
}


void ship::mergerooms() {
	std::cout<<"merging rooms" << std::endl;
	int doornumber = 0;
	for (int f = 0; f < floorcount; f++) {
		doornumber = 0;
		for (int y = 0; y < ysize; y++) {
			for (int x = 0; x < ysize; x++) {

				if (floor[f][y][x] == "_"  &&y > 0 && y < ysize) {
					if (floor[f][y + 1][x] == "." && floor[f][y - 1][x] == ".") {
						floor[f][y][x] = ".";
						//std::cout << "merging " << map[y][x] << " @ " << x << "," << y << std::endl;
					}
				}
				else if (floor[f][y][x] == "|"&&x > 0 && x < xsize) {
					if (floor[f][y][x + 1] == "."&&floor[f][y][x - 1] == ".") {

						floor[f][y][x] = ".";
						//std::cout << "merging "<< map[y][x ]<<" @ "<<x<<","<<y << std::endl;
					}
				}
				else
					if (floor[f][y][x] == ","  &&y > 0 && y < ysize) {
						if (floor[f][y + 1][x] == "|" && floor[f][y - 1][x] == "|") {
							floor[f][y][x] = "|";
							//std::cout << "merging " << map[y][x] << " @ " << x << "," << y << std::endl;
						}
					}
					else if (floor[f][y][x] == ","&&x > 0 && x < xsize) {
						if (floor[f][y][x + 1] == "_"&&floor[f][y][x - 1] == "_") {

							floor[f][y][x] = "_";
							//std::cout << "merging "<< map[y][x ]<<" @ "<<x<<","<<y << std::endl;
						}
					}
					else
						if (floor[f][y][x] == "d") {//removes doors
							if (y == 0 || y == ysize - 1) {// if the door is located on the left/right side of the map
								floor[f][y][x] = "_";

							}
							else if (x == 0 || x == xsize - 1) {//if the door is located ont the top/bottom of the map
								floor[f][y][x] = "|";

							}
							else if ((floor[f][y][x + 1] == "."&&floor[f][y][x - 1] == ".") || (floor[f][y + 1][x] == "."&&floor[f][y - 1][x] == ".")) {
								floor[f][y][x] = ".";

							}
							else {
								//only add doors that have areas to connect to other doors/hallways
								if (floor[f][y - 1][x] == " " || floor[f][y][x + 1] == " " || floor[f][y + 1][x] == " " || floor[f][y][x - 1] == " ") {
									dcor temp;
									temp.x = x;
									temp.y = y;
									doornumber++;
									rmdoors[f].push_back(temp);
								}
							}

						}

			}

		}
		std::cout << "doors on floor: " << f + 1 << " is " << doornumber << std::endl;
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
	int temp1 = 0;
	int temp2 = 0;

	for (int f = 0; f < floorcount-1; f++) {

		 temp1 = 0;
		 temp2 = 0;


		for (int i = 0; i < rmdoors[f].size(); i++) {// run through all of the doors
			connecting = true;
			x = rmdoors[f][i].x;
			y = rmdoors[f][i].y;


			//chcking to see if it is connected to the hallway
			if (floor[f][y][x + 1] != "H"  && floor[f][y + 1][x] != "H"
				&& floor[f][y][x - 1] != "H" && floor[f][y - 1][x] != "H") {

				//check to see were to place the hallway
				n = false;
				e = false;
				s = false;
				w = false;
				tdedge = false;
				lredge = false;
				if (floor[f][y - 1][x] == " ") {//picks the starting direction
					n = true;
				}
				else if (floor[f][y][x + 1] == " ") {
					e = true;
				}
				else if (floor[f][y + 1][x] == " ") {
					s = true;
				}
				else if (floor[f][y][x - 1] == " ") {
					w = true;
				}

				scouting = true;

				while (connecting) {// connecting it to to the hallway/another door only moving one block per cycle

					if (scouting) {//moving streight untill it hits a wall/object
						if (n) {//going north
							y--;
							if (y >= 0) {
								if (floor[f][y][x] == " ") {//if it is empty then add a hallway
									floor[f][y][x] = "H";

									//check to see if the soundings are a door/hallway

									if (y - 1 >= 0 && y + 1 < ysize) {
										if (floor[f][y - 1][x] == "H" || floor[f][y][x - 1] == "H" || floor[f][y - 1][x] == "d" || floor[f][y][x - 1] == "d") {
											scouting = false;
											connecting = false;
										}
									}

									if (x - 1 >= 0 && x + 1 < xsize) {
										if (floor[f][y][x + 1] == "H" || floor[f][y][x + 1] == "d") {
											scouting = false;
											connecting = false;
										}
									}


								}
								else if (floor[f][y][x] == "_" || floor[f][y][x] == "|") {
									floor[f][y][x] = "d";
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
								temp2++;

							}
						}
						else if (e) {//going east
							x++;
							if (x < xsize) {
								if (floor[f][y][x] == " ") {//if it is empty then add a hallway
									floor[f][y][x] = "H";

									//check to see if the soundings are a door/hallway

									if (y - 1 >= 0 && y + 1 < ysize) {
										if ((floor[f][y - 1][x] == "H" || floor[f][y + 1][x] == "H") ||
											(floor[f][y - 1][x] == "d" || floor[f][y + 1][x] == "d")) {
											scouting = false;
											connecting = false;
										}
									}
									if (x - 1 >= 0 && x + 1 < xsize) {
										if (floor[f][y][x + 1] == "H" || floor[f][y][x + 1] == "d") {
											scouting = false;
											connecting = false;
										}
									}


								}
								else if (floor[f][y][x] == "_" || floor[f][y][x] == "|") {
									floor[f][y][x] = "d";
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
								temp1++;
								x--;
								connecting = false;
							}

						}
						else if (s) {//going south
							y++;
							if (y < ysize) {
								if (floor[f][y][x] == " ") {//if it is empty then add a hallway
									floor[f][y][x] = "H";

									//check to see if the soundings are a door/hallway

									if (y - 1 >= 0 && y + 1 < ysize) {
										if (floor[f][y + 1][x] == "H" || floor[f][y + 1][x] == "d") {
											scouting = false;
											connecting = false;
										}
									}

									if (x - 1 >= 0 && x + 1 < xsize) {
										if ((floor[f][y][x + 1] == "H" || floor[f][y][x - 1] == "H") ||
											(floor[f][y][x + 1] == "d" || floor[f][y][x - 1] == "d")) {
											scouting = false;
											connecting = false;
										}
									}


								}
								else if (floor[f][y][x] == "_" || floor[f][y][x] == "|") {
									floor[f][y][x] = "d";
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
								temp2++;
								y--;
								connecting = false;
							}
						}
						else if (w) {//going west
							x--;
							if (x >= 0) {
								if (floor[f][y][x] == " ") {//if it is empty then add a hallway
									floor[f][y][x] = "H";
									//check to see if the soundings are a door/hallway
									if (y - 1 >= 0 && y + 1 < ysize) {
										if (floor[f][y + 1][x] == "H" || floor[f][y + 1][x] == "d" || floor[f][y - 1][x] == "H" || floor[f][y - 1][x] == "d") {
											scouting = false;
											connecting = false;
										}
									}

									if (x - 1 >= 0 && x + 1 < xsize) {
										if ((floor[f][y][x - 1] == "H") || floor[f][y][x - 1] == "d") {
											scouting = false;
											connecting = false;
										}
									}

								}
								else if (floor[f][y][x] == "_" || floor[f][y][x] == "|") {
									floor[f][y][x] = "d";
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
								temp1++;
								x++;
								connecting = false;
							}
						}

					}
					else {//traces the object that it 
						if (lredge) {//if the hallwalys run into the edge
							//std::cout << "hallway hit left or right wall" << std::endl;
							//temp1++;
						}
						else if (tdedge) {//if the hallwalys run into the edge
							//std::cout << "hallway hit top or bottom wall" << std::endl;
							//temp2++;
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
	std::cout << temp2 << " hallway hit top or bottom wall" << std::endl;
	std::cout << temp1 << " hallway hit left or right wall" << std::endl;
}


void ship::detectRoom() {
	int number = 0;
	bool tracing;
	bool add;
	int oren; // the starting direction 1 right, 2 down, 3 left, 4 up
	int tx;
	int ty;

	

	//go through the entire map
	for (int y = 0; y < ysize; y++) {
		for (int x = 0; x < xsize; x++) {

			
			if (floor[0][y][x] == ",") {//if it finds a comma
				if (x+1<xsize && (floor[0][y][x + 1] == "_" || floor[0][y][x + 1] == "d")) {//checks the spot to the right
					if (y+1<ysize&& (floor[0][y + 1][x] == "|" || floor[0][y + 1][x] == "d")) {//checks the spot bellow the start
						add = false;
						tracing = true;
						tx = x+1;
						ty = y;
						oren = 1;
						while (tracing) {
							switch (oren)
							{
							case 1://moving right
								if (tx + 1 < xsize) {
									if (floor[0][ty][tx + 1] == ",") {//need to turn
										tx++;
										if (ty+1<ysize && floor[0][ty + 1][tx] == "|") {
											ty++;
											oren = 2;
										}
										else if (ty - 1 > 0 && floor[0][ty - 1][tx] == "|") {
											ty--;
											oren = 4;
										}
										else if (tx + 1 < xsize&&floor[0][ty][tx + 1] == "_") {
											tx++;
										}
										else {
											tracing = false;
										}
									}
									
									else {
										tracing = false;
									}
								}
								else {
									tracing = false;
								}
								break;
							case 2:// moving down
								if (ty + 1 < ysize) {
									if (floor[0][ty + 1][tx]==",") {
										ty++;
										if (tx-1 >0 && floor[0][ty][tx - 1] == "_") {
											oren = 3;
											tx--;
										}
										else if (ty + 1 < ysize&&floor[0][ty + 1][tx] == "|") {
											ty++;
										}
										else if (floor[0][ty][tx++] == "_") {
											tx++;
											oren = 1;
										}
										else {
											tracing = false;
										}


									}
									else {
										ty++;
									}
								}
								else {
									tracing = false;
								}
								break;
							case 3:// moving left
								if (tx - 1 >0) {
									if (floor[0][ty][tx - 1] == ",") {//need to turn
										tx--;
										if (floor[0][ty - 1][tx] == "|") {
											ty--;
											oren = 4;
										}
										else if (floor[0][ty + 1][tx] == "|") {
											ty++;
											oren = 2;
										}
										
										else {
											tracing = false;
										}
									}
									else if (floor[0][ty][tx - 1] == "_") {
										tx--;
									}
									else {
										tracing = false;
									}
								}
								else {
									tracing = false;
								}
								
								break;
							case 4:// moving up
								if (ty - 1 >0) {
									if (floor[0][ty - 1][tx] == ",") {
										ty--;
										if (ty == y && tx == x) {
											tracing = true;
											add = true;
										}else
										 if (floor[0][ty][tx + 1] == "_") {
										tx++;
										oren = 1;
									}
										if (floor[0][ty][tx - 1] == "_") {
											oren = 3;
											tx--;
										}
										else if (floor[0][ty - 1][tx] == "|") {
											ty--;
										}
										
										else {
											tracing = false;
										}


									}
									else {
										ty--;
									}
								}
								else {
									tracing = false;
								}
								break;
							default:
								std::cout << "problem with orentation" << std::endl;
								break;
							}

						}

						if (add) {
							number++;
						}

					}
				}


			}

		}
		
	}

	std::cout << "the number of rooms = " << number << std::endl;
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
				std::cout << floor[0][i][y];
			}
		}
		std::cout << std::endl;
	}

}

void ship::print() {

	for (int i = 0; i < floor.size(); i++) {
		std::cout << "floor #: " << i + 1 << std::endl;
		for (int x = 0; x < xsize; x++) {
			for (int y = 0; y < ysize; y++) {

				std::cout << floor[i][x][y];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}