#pragma once
#include "room.h"
#include <vector>
#include <string>
#include "ship.h"

class RoomCreator{

public:
	RoomCreator();
	RoomCreator(int x, int y, int f, bool multif, bool rand);
	~RoomCreator();

	void readinfurniture();
	void readinrooms();

	void setconditions(int x, int y, int f, bool multif, bool rand);

	void createFurniture();
	void removeFurniture(int i);

	void createRoom();
	void removeRooms();

	room createroomforship();//return a room to a ship


	std::vector<std::string> getSections() { return sections; }
	std::vector<bool> getRestrctions() { return restritions; }

	void exportfurniture();
	void exportRooms();

	void importfurniture();
	void importRooms();

	ship makeship();


private:
	bool multipart;//rooms that are oddly shaped
	bool Mstories; // whether to generate rooms that consist over multiple floors

	std::vector<std::string> sections;
	std::vector<bool> restritions;

	std::string ** working;// what the creator is working with

	int xsize;
	int ysize;
	int floors;

	std::vector<room> Roomlist;
	std::vector<furniture> furniturelist;

};

