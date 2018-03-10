#ifndef HEADERFILE_model
#define HEADERFILE_model

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

		//helper methods
		static bool checkIfInBounds(int size, bool orientation, int startX, int startY); 


	private:
		int size;
		bool orientation;
		int startX; 
		int startY;
		int life;
		int squares[size][2];

		// helper methods
		void setUpSquares();
		
		
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