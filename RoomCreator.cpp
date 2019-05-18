#include "RoomCreator.h"
#include <iostream>
#include <string>


RoomCreator::RoomCreator(){
	setconditions(1, 1, 1, false, true);
}

RoomCreator::RoomCreator(int x, int y, int f, bool multif, bool rand) {
	setconditions(x, y, f, multif, rand);
}

RoomCreator::~RoomCreator(){

}


void RoomCreator::readinfurniture() {

}

void RoomCreator::readinrooms() {

}

void RoomCreator::setconditions(int x, int y, int f, bool multif, bool rand) {
	xsize = x;
	ysize = y;
	floors = f;
	Mstories = multif;
	multipart = rand;
}

void RoomCreator::createFurniture() {
	std::string line;
	std::string name;
	std::string id;
	std::string section;
	bool manned;
	bool obstrut;
	int xs;
	int ys;

	std::cout << "input name" << std::endl;
	getline(std::cin, line);
	name = line;

	std::cout << "input id" << std::endl;
	getline(std::cin, line);
	id = line;

	std::cout << "input section" << std::endl;
	getline(std::cin, line);
	section = line;

	std::cout << "input manned" << std::endl;
	getline(std::cin, line);
	if (line == "true") {
		manned = true;
	}
	else {
		manned = false;
	}

	std::cout << "input xsize" << std::endl;
	getline(std::cin, line);
	xs = atoi(line.c_str());

	std::cout << "input ysize" << std::endl;
	getline(std::cin, line);
	ys = atoi(line.c_str());
	std::cout << "does the obect obstruct movement" << std::endl;
	getline(std::cin, line);
	if (line == "true") {
		obstrut = true;
	}
	else {
		obstrut = false;
	}

	furniture fun(name, id, section, xs, ys, obstrut, manned);

	furniturelist.push_back(fun);
}

void RoomCreator::removeFurniture(int i) {
	int temp = furniturelist.size()-1;
	std::swap(furniturelist[i], furniturelist[temp]);
	furniturelist.pop_back();

}

void RoomCreator::createRoom() {

}
void RoomCreator::removeRooms() {

}

room RoomCreator::createroomforship() {

}


void RoomCreator::exportfurniture() {

}

void RoomCreator::importfurniture() {

}

void RoomCreator::exportRooms() {

}

void RoomCreator::importRooms() {

}


ship RoomCreator::makeship() {
	int temp = floors;
	if(!Mstories){
		floors = 1;
	}

	


	ship output(xsize, ysize, floors, multipart);
	
	


	if (!Mstories) {
		floors = temp;
	}
	return output;
}



