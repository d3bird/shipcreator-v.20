#pragma once
#include <string>
class monster
{
public:
	monster(std::string ra,std::string i,int nums[4]){
		xloc = 0;
		floc = 0;
		yloc = 0;
		ws = nums[0];
		Mdam = nums[1];
		Rdam = nums[2];
		hp = nums[3];
		maxhp = nums[3];
	
		id = i;
		race = ra;
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
	void setrace(std::string i) { race = i; }
	
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

