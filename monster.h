#pragma once
#include <string>
class monster
{
public:
	monster(std::string i, std::string r){
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

	std::string getid() { return id; }
	void setid(std::string i) { id = i; }
	void setname(std::string na) { name = na; }
	std::string getname() { return name; }
	std::string getrace() { return race; }

	void setmhp(int i) { maxhp = i; }
	int getmhp() { return maxhp;}

	int getMdam() { return Mdam; }
	void setMdam(int i) { Mdam = i; }
	int getRdam() { return Rdam; }
	void setRdam(int i) { Rdam = i; }
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
	std::string id;
};

