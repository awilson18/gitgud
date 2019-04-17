#include "PA8.h"

/*
 Name: Alec Wilson
 Class: Cpsc 121, Spring 2019
 Date: April 15, 2019
 Programming Assignment: PA8                                                               
 Description: This is 
 the main function for a game of battleship
 Notes: 
*/

int main() {
	srand(time(0));
	char P1SolutionArray[rows][cols];
	char P2SolutionArray[rows][cols];
	char shotFiredArray[rows][cols];
	char cpuShotsFiredArray[rows][cols];
	int playerOrder;
	
	gameRules();
	fillArray(P1SolutionArray);
	fillArray(P2SolutionArray);
	fillArray(shotFiredArray);
	fillArray(cpuShotsFiredArray);
	playerOrder = firstPlayers();
	placeShips(P1SolutionArray);
	randomlyPlaceShips(P2SolutionArray);
	printArray(P1SolutionArray);
	cout << endl << endl;
	cout << "---------------------------------\n";
	playGame(P1SolutionArray, P2SolutionArray, shotFiredArray, cpuShotsFiredArray, playerOrder);
	
	
	
	
	
	
	
	
	
	return(0);
}
