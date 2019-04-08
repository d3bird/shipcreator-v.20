#include <iostream>
#include <stdlib.h>
#include "ship.h"
#include "monster.h"
#include <vector>
#include <fstream>

std::vector<monster*> races;
std::vector<monster> monsters;
std::vector<std::string> names;

void printKey() {
	std::cout << ". = space in the room" << std::endl;
	std::cout << ", = corner" << std::endl;
	std::cout << "d = door/hidden door" << std::endl;
	std::cout << "| = wall " << std::endl;
	std::cout << "_ = wall" << std::endl;
	std::cout << "H = hallway" << std::endl;
	std::cout << "s stair case to floor right above or below" << std::endl;
	if (monsters.size() > 0) {
		std::cout << "these are the creatures on ship" << std::endl;
		for (int i = 0; i < monsters.size(); i++) {
			std::cout << monsters[i].getid() << " = " << monsters[i].getname() << " who is a " << monsters[i].getrace() << std::endl;
		}
	}
}

void drawmenu() {
	system("cls");
	std::cout << "type in what you want to do" << std::endl;
	std::cout << "1: blank ship" << std::endl;
	std::cout << "2: ship with filled rooms (no life)" << std::endl;
	std::cout << "3: ship with filled rooms (with life)" << std::endl;
	std::cout << "4 grid ship" << std::endl;
	std::cout << "4 grid ship with filled " << std::endl;
	std::cout << "5: add room" << std::endl;
	std::cout << "6: remoce room" << std::endl;
	std::cout << "7: add life form" << std::endl;
	std::cout << "8: remove life form" << std::endl;
	std::cout << "11: settings" << std::endl;
	std::cout << "12: quit" << std::endl;
	std::cout << "13: help" << std::endl;

}

void readinnames() {
	std::string line;
	std::ifstream myfile("names");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//std::cout << line << '\n';
			names.push_back(line);
		}
		myfile.close();
	}

	else std::cout << "Unable to open file"<<std::endl;

}
void readinraces() {
	std::string line;
	std::ifstream myfile("races");
	int counter = 0;
	std::string r;
	monster* temp;
	int temp2;
	if (myfile.is_open())
	{
		temp = new monster('a',"temp");
		while (getline(myfile, line))
		{
			
			r = "";
			std::cout << line << '\n';
			switch (counter){
			case 0:
				r = line;
				break;
			case 1:
				temp = new monster(line[0], r);
				break;
			case 2:
				temp2 = atoi(line.c_str());
				temp->setws(temp2);
				break;
			case 3:
				temp2 = atoi(line.c_str());
				temp->setmhp(temp2);
				break;
			case 4:
				temp2 = atoi(line.c_str());
				temp->setRdam(temp2);
				break;
			case 5:
				temp2 = atoi(line.c_str());
				temp->setMdam(temp2);
				break;
			default:
				std::cout << "there was a problem exporting the races" << std::endl;
				break;
			}
			counter++;
			if (counter >= 6) {
				counter = 0;
			}
		}
		myfile.close();
	}

	else std::cout << "Unable to open file" << std::endl;

}
void exportraces() {
	std::ofstream myfile;
	myfile.open("races");
	//myfile << "this is writen in the race file \n";
	for (int i = 0; i < races.size(); i++) {
		myfile << races[i]->getrace()<<"\n";
		myfile << races[i]->getid() << "\n";
		myfile << races[i]->getws() << "\n";
		myfile << races[i]->getmhp() << "\n";
		myfile << races[i]->getRdam() << "\n";
		myfile << races[i]->getMdam() << "\n";
	}
	myfile.close();

	for (int i = 0; i < races.size(); i++) {//removeing them from memory after export
		delete races[i];
	}
}

void printRaces() {
	for (int i = 0; i < races.size(); i++) {
		std::cout << races[i]->getrace() << std::endl;
		std::cout << races[i]->getid() << std::endl;
		std::cout << races[i]->getws() << std::endl;
		std::cout << races[i]->getmhp() << std::endl;
		std::cout << races[i]->getRdam() << std::endl;
		std::cout << races[i]->getMdam() << std::endl;
		std::cout << std::endl;
	}


}

int main() {
	bool running = true;
	//drawmenu();
	int xsize;
	int ysize;
	int floorcount;
	int input = -1;

	ship *s;

	readinnames();
	readinraces();

	std::cin.get();
	running = false;
	while (running) {

		switch (input)
		{
		case 1:
			std::cout << "input max width, then max height" << std::endl;
			std::cin >> xsize;
			std::cin >> ysize;
			std::cout << "how many floors do you want" << std::endl;
			std::cin >> floorcount;
			if (floorcount <= 0) {
				floorcount = 1;
			}
			s =new ship(xsize, ysize, floorcount);
			std::cout << "filling space" << std::endl;
			s->fillspace();
			std::cout << "merging rooms" << std::endl;
			s->mergerooms();
			std::cout << "generating hallways" << std::endl;
			s->generateHallways();
			std::cout << "printing" << std::endl;
			s->print();
			printKey();
		//	s->detectRoom();
			delete s;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			std::cout << "create a race" << std::endl;
			std::string line;
			std::string r;
			int temp2;
			
			std::cout << "enter race name" << std::endl;
			getline(std::cin, line);
			r = line;
			std::cout << "enter race id char" << std::endl;
			getline(std::cin, line);
			monster * temp = new monster(line[0], r);
			std::cout << "enter race work speed" << std::endl;
			getline(std::cin, line);
			temp2 = atoi(line.c_str());
			temp->setws(temp2);
			std::cout << "enter race max hp" << std::endl;
			getline(std::cin, line);
			temp2 = atoi(line.c_str());
			temp->setmhp(temp2);
			std::cout << "enter race ranged damage" << std::endl;
			getline(std::cin, line);
			temp2 = atoi(line.c_str());
			temp->setRdam(temp2);
			std::cout << "enter race melee damage" << std::endl;
			getline(std::cin, line);
			temp2 = atoi(line.c_str());
			temp->setMdam(temp2);
			races.push_back(temp);
			break;
		case 8:
			std::cout << "remove a race" << std::endl;
			printRaces();
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			running = false;
			break;
		case 13:
			break;

		default:
			std::cout << "that is not an option" << std::endl;
			break;
		}
		if (running) {
			std::cin >> input;
			drawmenu();
		}
	}

	exportraces();
	return 0;
}