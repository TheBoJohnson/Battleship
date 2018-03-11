#ifndef HEADERFILE_model
#define HEADERFILE_model

#include <string>

//class for the ships
class Ship{
	public:
		Ship(std::string name, int s, bool o, int sX, int sY);

		int getSize();
		bool getOrientation();
		int getStartX(); 
		int getStartY();
		int getLife();
		void takeLife();
		std::string getName();

		//helper methods
		static bool checkIfInBounds(int size, bool orientation, int startX, int startY); 


	protected:
		int size;
		bool orientation;
		int startX; 
		int startY;
		int life;
		std::string name;
		int* squares[][2];

		// helper methods
		void setUpSquares();
		
		
};

class Destroyer : public Ship{

};


class Submarine : public Ship{

};

class Cruiser : public Ship{

};


class Battleship : public Ship{

};

class Carrier : public Ship{

};




// base class for the ocean model
class OceanModel{
	public:
		// Default Contructor for the Ocean Model
		OceanModel();

		void changeTile(int x, int y, int type);
		int getTile(int x, int y);

	protected:
		// Array representation of the Ocean
		int oceanArray[10][10];
};

// class for the User ocean
class userOceanModel : public OceanModel{
	public:
		userOceanModel();
		bool checkIfOccupied(int startX, int startY, bool orientation, int size);
		void importShip(Ship& toAdd);
};

// class for the enemy ocean
class enemyOceanModel : public OceanModel{
	public:
		enemyOceanModel();
		void markHit(int xPos, int yPos);
		void markMiss(int xPos, int yPos);
};
#endif