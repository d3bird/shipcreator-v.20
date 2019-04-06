#pragma once
#include <string>
class monster
{
public:
	monster(char i){
		xloc = 0;
		floc = 0;
		yloc = 0;
		ws = 10;
		Mdam = 5;
		Rdam = 0;
		hp = 10;
		maxhp = 10;
	}

	~monster(){}

	void setws(int i) { ws = i; }
	int getws() { return ws; }

	void setf(int t) { floc = t; }
	void setx(int t) { xloc = t; }
	void sety(int t) { yloc = t; }

	int getx() { return xloc; }
	int gety() { return yloc; }
	int getf() { return floc; }

private:
	int xloc;
	int floc;
	int yloc;
	int maxhp;
	int hp;
	int Mdam;
	int Rdam;
	int ws;// how fast it works in a room
	std::string name;
	char id;
};

