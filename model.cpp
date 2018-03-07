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


//class for the ships
class Ship{
	public:
		Ship(int s, bool o, int sX, int sY);

		int getSize();
		bool getOrientation();
		int getStartX(); 
		int getStartY();
		int getLife();
		void takeLife();

	private:
		int size;
		bool orientation;
		int startX; 
		int startY;
		int life; 
};

Ship::Ship(int s, bool o, int sX, int sY){
	size = life = s;
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

int Ship::getLife(){
	return life; 
}

void Ship::takeLife(){
	life--;
}


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
		bool checkIfOccupied(int startX, int startY, bool orientation, int size);
		void importShip(Ship& toAdd);
};

userOceanModel::userOceanModel(){
	OceanModel();
}

void userOceanModel::importShip(Ship& toAdd){
	if(toAdd.getOrientation() == VERT){
		if(toAdd.getSize() + toAdd.getStartY() > 9){
			cout << "Ship is not in bounds" << endl;
		}
		else if(!checkIfOccupied(toAdd.getStartX(), toAdd.getStartY(), toAdd.getOrientation(), toAdd.getSize())){
			cout << "You are trying to place the ship in tiles that are already occupied" << endl;
		}
		else{
			for(int i = toAdd.getStartY(); i < toAdd.getStartY() + toAdd.getSize(); i++){
				oceanArray[i][toAdd.getStartX()] = SHIP;
			}
		}
	}
	else{
		if(toAdd.getSize() + toAdd.getStartX() > 9){
			cout << "The Ship is not in bounds" << endl;
		}
		else if(!checkIfOccupied(toAdd.getStartX(), toAdd.getStartY(), toAdd.getOrientation(), toAdd.getSize())){
			cout << "You are trying to place the ship in tiles that are alrady occupied" << endl;
		}
		else{
			for(int i = toAdd.getStartX(); i < toAdd.getStartX() + toAdd.getSize(); i++){
				oceanArray[toAdd.getStartY()][i] = SHIP;
			}
		}
	}
}


bool userOceanModel::checkIfOccupied(int startX, int startY, bool orientation, int size){
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
class enemyOceanModel : public OceanModel{
	public:
		enemyOceanModel();
		void markHit(int xPos, int yPos);
		void markMiss(int xPos, int yPos);
};

// constructor
enemyOceanModel::enemyOceanModel(){
	OceanModel();
}


void enemyOceanModel::markHit(int xPos, int yPos){
	changeTile(xPos, yPos, HIT);
}

void enemyOceanModel::markMiss(int xPos, int yPos){
	changeTile(xPos, yPos, MISS); 
}