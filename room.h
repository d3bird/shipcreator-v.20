#pragma once
#include <vector>
#include <string>

class furniture {
public:

	furniture();

	std::string getname() { return name; }
	void setname(std::string n) { name = n; }
	std::string getid() { return id; }
	void setID(std::string i) { id = i; }
	std::string getsection() { return section; }
	void setsection(std::string s) { section = s; }
	std::string getmannedaffect() { return name; }
	void setmannedaffect(std::string s) { mannedaffect = s; }

	int getxsize() { return xs; }
	int getysize() { return ys; }

	bool getobstuted() { return obstrut; }
	bool getmanned() { return manned; }

private:
	std::string name;
	std::string id;
	int xs;//xsize
	int ys;//ysize
	std::string section;//i.e. sciance, recreation, securitey e.c.t..
	bool obstrut;
	bool manned;
	std::string mannedaffect;
};


class room {
public:

	room(int xl, int yl, int f) {
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