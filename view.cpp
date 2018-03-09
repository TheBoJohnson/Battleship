#include <iostream>
#include <string>

#include "model.h"
#include "view.h"

// macros for each type of square on a map
#define EMPTY 0
#define SHIP 1
#define HIT 2
#define MISS 3

// macros for the orientation that ships can have
#define HORIZ true
#define VERT false

using namespace std;

string parseOcean(OceanModel& model){
	string returner = "     1   2   3   4   5   6   7   8   9   10";
	
	for(int i = 0; i < 10; i++){
		char letterLabel = i + 65;
		returner += "\n" + string(1, letterLabel) + "    ";

		for(int j = 0; j < 10; j++){
			switch(model.getTile(j, i)){
				case EMPTY:
					returner += "-";
					break;
				case SHIP:
					returner += "#";
					break;
				case HIT:
					returner += "X";
					break;
				case MISS:
					returner += "O";
					break;
			}
			
			returner += "   ";
		}
		returner += "\n";
	}
	return returner;
}

void displayOcean(OceanModel& model){
	cout << parseOcean(model);
}