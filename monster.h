#pragma once
#include <string>
class monster
{
public:
	monster(char i, std::string r){
		xloc = 0;
		floc = 0;
		yloc = 0;
		ws = 10;
		Mdam = 5;
		Rdam = 0;
		hp = 10;
		maxhp = 10;
		race = r;
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

	char getid() { return id; }
	void setid(char i) { id = i; }
	void setname(std::string na) { name = na; }
	std::string getname() { return name; }
	std::string getrace() { return race; }

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
	std::string race;
	char id;
};

