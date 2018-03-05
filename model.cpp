#include <iostream>

// macros for each type of square on a map
#define EMPTY 0
#define SHIP 1
#define HIT 2
#define MISS 3

// macros for the orientation that ships can have
#define HORIZ true
#define VERT false

using namespace std;

// base class for the ocean model
class OceanModel{
	public:
		// Default Contructor for the Ocean Model
		OceanModel();

		void changeTile(int x, int y, int type);

	protected:
		// Array representation of the Ocean
		int oceanArray[10][10];
};

OceanModel::OceanModel(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			oceanArray[i][j] = EMPTY;
		}
	}
}

void OceanModel::changeTile(int x, int y, int type){
	oceanArray[x][y] = type; 
}



// class for the User ocean
class userOceanModel : public OceanModel{
	public:
		userOceanModel();
		bool checkIfOccupied(int startX, int startY, int orientation, int size);

	private:
		void importShip(Ship toAdd);

};

void userOceanModel::importShip(Ship toAdd){
	if(toAdd.getOrientation == VERT){
		if(toAdd.getSize() + toAdd.getStartY > 10){
			cout << "Ship is not in bounds" << endl;
		}
		else if(!checkIfOccupied(toAdd.getStartX(), toAdd.getStartY(), toAdd.getOrientation(), toAdd.getSize())){
			cout << "You are trying to place the ship in tiles that are already occupied" << endl;
		}
		else{
			for(int i = startY; i < startY + size; i++){
				oceanArray[startX][startY] = SHIP;
			}
		}
	}

}


bool userOceanModel::checkIfOccupied(int startX, int startY, int orientation, int size){
	if(orientation == VERT){
		for(int i = startY; i < startY + size; i++){
			if(oceanArray[startX][i] == SHIP){
				return false;
			}
		}
		return true;
	}
	else{
		for(int i = startX; i < startX + size; i++){
			if(oceanArray[i][startY] == SHIP){
				return false;
			}
		}
		return true;
	}
}

// class for the enemy ocean





//class for the ships

class Ship{
	public:
		Ship(int s, bool o, int sX, int sY);

		int getSize();
		bool getOrientation();
		int getStartX; 
		int getStartY;

	private:
		int size;
		bool orientation;
		int startX; 
		int startY;
};

void Ship::Ship(int s, int o, int sX, int sY){
	size = s;
	orientation = o;
	startX = sX; 
	startY = sY;
}

int Ship::getSize(){
	return size;
}

bool Ship::getOrientation(){
	return orientation;
}

int Ship::getStartX(){
	return startX;
}

int Ship::getStartY(){
	return startY;
}

int main(){




	return 0;
}