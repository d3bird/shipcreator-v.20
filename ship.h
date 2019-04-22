#pragma once
#include <string>
#include <vector>

struct dcor
{
	int x;
	int y;
};

class furniture{
public:

	

private:
	std::string name;
	std::string id;
	int xs;//xsize
	int ys;//ysize
	std::string section;//i.e. sciance, recreation, securitey e.c.t..

};


class room {
public:

	room(int xl, int yl,int f) {
		x = xl;
		y = yl;
		bottomfloor = f;
		multifloor = false;
		topfloor = f;
		rsize = 0;
	}

	std::vector<int>& getturns() { return turns; }

	void setSize(int s) { rsize = s; }
	int size() { return rsize; }
	int getx() { return x; }
	int gety() { return y; }
	bool ismultifloor() { return multifloor; }
	void settopfloor(int f) { topfloor = f; }
	int gettopfloor() { return topfloor; }
	int getbottomfloor() { return bottomfloor; }

private:
	int rsize;
	int x;
	int y;
	int bottomfloor;
	int topfloor;
	bool multifloor;
	std::string section;
	std::vector<int> turns;
};


class ship
{
public:
	ship(int x, int y, int i);// for the random ship
	ship(int x, int y, int i, bool t);// for the grid ship
	~ship();

	void gen_blank_map();
	void fillspace();
	void print();
	void debugprint();
	void mergerooms();
	void generateHallways();
	void fillrooms();

	void detectRoom();


	// functions for generating grid ships

	void grid_fillspace();
	void grid_hallways();
	void grid_fillRooms();
	void grid_detectrooms();

	void setmaxroomsize(int x) { maxrs = x; }
	void setminroomsize(int x) { minrs = x; }
	int getmaxroomsize() { return maxrs; }
	int getminroomsize() { return minrs; }

	int gethalldist() { return halldist; }
	void sethalldist(int i) { halldist = i; }

	std::string ** getmap() { return map; }

private:
	bool grid;

	int halldist;//the size of rooms in the gridship

	int maxrs;
	int minrs;
	int xsize;
	int ysize;
	int floorcount;
	int roomnumber;
	std::string ** map;
	std::vector< std::string **> floor;
	std::vector< std::vector<dcor> > rmdoors;
	


};

