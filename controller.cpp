#include <iostream>

#include "model.h"
#include "view.h"

using namespace std;

/*
Game States

1. Set up
	Allow user to place ships 

	Use Algorithm to randomly place ships for the cpu

	Flip Coin to see who goes first

2. In Game

	Player and cpu go back and forth in guessing where ships are

		Data Strutctre to ensure that the users guesses have been tracked 
			(can simply check the state of the square they guessed on for that)

		Code proper algorithm for the cpu to guess on 

			Two States: Seeking and Destroying

				Seeking- The cpu randomly selects a square to shoot at if its a hit go
				to the destroying state and if its a miss stay in the seeking state

				Destroying- When in this state, after the initial hit, it the cpu will shoot
				at the adjacent square up down to the left and to the right of the of the 
				square until it gets another hit. Then it contines to shoot in the direction 
				of the second hit until it destroys the ship. Then it returned back to the
				seeking.
		
		CPU needs to keep track of squares it has guessed on

		Need to check if win condition is met everytime a ship gets destroyed



3. Post Game

	List Stats for the game
		Number of shots taken
		Accuracy

*/

class Game{
	public:

		// Game State Methods
		void setupGame();
		void startGame();

		bool isgameWon();

		// Helper Methods
		void placeCpuShips(); 
		void placeUserShips();

		void takeUserGuess();
		void takeCpuGuess();


	private:
		// Stats Variables
		int userNumShots = 0;
		int cpuNumShots = 0;

		// Arrays for ships 
		Ships userShips[5];
		Ships cpuShips[5];

		// Players Maps
		userOceanModel playersOceanTiles; 
		enemyOceanModel playersShootingTiles;

		// CPU Maps
		userOceanModel cpuOceanTiles; 
		ememyOceanModel cpuShootingTiles;
};



void Game::setupGame(){
	void placeCpuShips();
	void placeUserShips();


}

void Game::placeCpuShips(){

}


void placeUserShips(){
	bool isDone = false;
	int state = 0;

	while(!isDone){
		switch(state){
			case 0:
				cout << "Place your Destroyer (2)." << endl;
				// check if valid square and place. If it is iterate state
				break;
			case 1:
				cout << "Place your submarine (3)" << endl;
				// check if valid square and place. If it is iterate state
				break;
			case 2:
				cout << "Place your cruiser (3)" << endl;
				// check if valid square and place. If it is iterate state
				break;
			case 3:
				cout << "Place your Battleship (4)" << endl;
				// check if valid square and place. If it is iterate state
				break;
			case 4:
				cout << "Place your Carrier (5)" << endl;
				// check if valid square and place. If it is make isDone true
				break;
		}
	}
}














int main(){






	return 0;
}
