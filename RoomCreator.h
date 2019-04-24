#pragma once
#include "room.h"
#include <vector>
#include <string>


class RoomCreator{

public:
	RoomCreator();
	~RoomCreator();

	void readinfurniture();
	void readinrooms();

	void setconditions();

	void createFurniture();
	void removeFurniture();

	void createRoom();
	void removeRooms();

	room createroomforship();//return a room to a ship


	std::vector<std::string> getSections() { return sections; }
	std::vector<bool> getRestrctions() { return restritions; }

	void exportfurniture();
	void exportRooms();

private:
	bool multipart;//rooms that are oddly shaped
	bool Mstories; // whether to generate rooms that consist over multiple floors

	std::vector<std::string> sections;
	std::vector<bool> restritions;

	std::string ** working;// what the creator is working with

};

