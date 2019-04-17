#ifndef PA8_H
#define PA8_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>


using namespace std;
const int rows = 10;
const int cols = 10;
const string shipNames[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
const char shipSymbols[]= {'c', 'b', 'r', 's', 'd'};
const int shipSize[] = {5, 4, 3, 3, 2};

struct stats{
	int shotsFired = 0;
	int shotsMissed = 0;
	int shotsHit = 0;
	};

void gameRules();
void fillArray(char [][cols]);
void printArray(char [][cols]);
int firstPlayers();
int flipACoin();
void placeShips(char [][cols]);
void randomlyPlaceShips(char [][cols]);
void manuallyPlaceShips(char [][cols]);
void playGame(char [][cols],char [][cols],char [][cols], char [][cols], int);
void scanArray(char , char [][cols], char [][cols]);
#endif
