#pragma once
#include <string>

class ship
{
public:
	ship(int x, int y);
	~ship();

	void gen_blank_map();
	void fillspace();
	void print();

	

	void setmaxroomsize(int x) { maxrs = x; }
	void setminroomsize(int x) { minrs = x; }
	int getmaxroomsize() { return maxrs; }
	int getminroomsize() { return minrs; }



private:
	int maxrs;
	int minrs;
	int xsize;
	int ysize;
	int roomnumber;
	std::string ** map;
	


};

