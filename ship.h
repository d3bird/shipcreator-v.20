#pragma once
#include <string>
#include <vector>

struct dcor
{
	int x;
	int y;
};


class room {
public:

	room(int xl, int yl) {
		x = xl;
		
		y = yl;
		rsize = 0;
	}

	std::vector<int>& getturns() { return turns; }

	void setSize(int s) { rsize = s; }
	int size() { return rsize; }
	int getx() { return x; }
	int gety() { return y; }
private:
	int rsize;
	int x;
	int y;
	std::vector<int> turns;
};


class ship
{
public:
	ship(int x, int y, int i);
	~ship();

	void gen_blank_map();
	void fillspace();
	void print();
	void debugprint();
	void mergerooms();
	void generateHallways();
	void fillrooms();

	void detectRoom();

	void setmaxroomsize(int x) { maxrs = x; }
	void setminroomsize(int x) { minrs = x; }
	int getmaxroomsize() { return maxrs; }
	int getminroomsize() { return minrs; }

	std::string ** getmap() { return map; }

private:
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

