#include "PA8.h"
/*
 Name: Alec Wilson
 Class: Cpsc 121, Spring 2019
 Date: April 7, 2019
 Programming Assignment: PA7                                                                  
 Description: This is the functions of a game of battleship
 Notes: 
*/


/*************************************************************
 * Function: Fill array           	
 * Date Created: 04/05/19                  	        
 * Date Last Modified: 04/05/19                       
 * Description: fills an array with ~                	
 * Input parameters: An array	
 * Returns:An array filled with ~ chars       	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/
void fillArray(char arr[][cols]){
	int i, j;
	
	
	for (i = 0; i < rows; i++)
		{
		for (j = 0; j < cols; j++)
			{
			arr[i][j] = '~';
			}
		}
	}
	
/*************************************************************
 * Function: Print array           	
 * Date Created: 04/05/19                  	        
 * Date Last Modified: 04/16/19                       
 * Description: prints an array               	
 * Input parameters: An array	
 * Returns: a couted array      	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/
void printArray(char arr[][cols]){
	int i, j;
	cout << "  0 1 2 3 4 5 6 7 8 9\n";
	for (i = 0; i < rows; i++){
		cout << static_cast<char>(i + 65) << " ";
		for(j = 0; j < cols; j++)
			{
			cout << arr[i][j] << " ";
			
			}
		cout << endl;
		}
	}
/*************************************************************
 * Function: First Players          	
 * Date Created: 04/13/19                  	        
 * Date Last Modified: 04/13/19                       
 * Description: Determins which player goes first              	
 * Input parameters: Nothing	
 * Returns: player order      	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/

int firstPlayers(){
	int playerOrder;
	int i = 0;
	cout << "Who will be taking the first turn.\n1) Player 1.\n";
	cout << "2) Player 2.\n3) Random\nPlease enter a 1, 2, or 3: ";
	cin >> playerOrder;
	while (i == 0)
		{
		if (playerOrder != 1 && playerOrder != 2 && playerOrder != 3){
			cout << "Please enter a 1, 2, or 3: ";
			cin >> playerOrder;
			}
		else
			i++;
		}
		if (playerOrder == 3)
			{
			playerOrder = rand() % 2 + 1;
			if (playerOrder == 1)
				cout << "Player 1 will play first.\n";
			else
				cout << "Player 2 will play first.\n";
			}
	return playerOrder;
}

/*************************************************************
 * Function: Place Ships          	
 * Date Created: 04/05/19                  	        
 * Date Last Modified: 04/05/19                       
 * Description: Places the ships               	
 * Input parameters: An array	
 * Returns: A array with ships filled      	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/
			
void placeShips(char arr[][cols]){
	int placement;
	int i = 0;
	cout << "Would you like the place your ships manually or would you like";
	cout << " random placement. Please eneter 1 for random or 0 for manual: ";
	cin >> placement;
	while (i == 0)
		{
		if (placement != 0 && placement != 1)
			{
			cout << "Please eneter 1 for random and 0 for manual: ";
			cin >> placement;
			}
		else
			{
			i++;
			if (placement == 1)
				randomlyPlaceShips(arr);
			else
				manuallyPlaceShips(arr);
			}
		}
}

/*************************************************************
 * Function: Flip A Coin         	
 * Date Created: 04/05/19                  	        
 * Date Last Modified: 04/05/19                       
 * Description: flips a coin
 * Input parameters: An array	
 * Returns: either a 1 or 2      	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/
int flipACoin(){
	int result;
	result = rand() % 2 + 1;
	return result;
}

/*************************************************************
 * Function: Randomly Place Ships          	
 * Date Created: 04/05/19                  	        
 * Date Last Modified: 04/05/19                       
 * Description: Randomly Places the ships in teh array               	
 * Input parameters: An array	
 * Returns: An array filled with randomly places ships     	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/
 
void randomlyPlaceShips(char arr[][cols]){
	int i;
	int j = 0;
	int k;
	int l;
	int p;
	int sizeCheck;
	int orentation;
	int firstPos;
	int secondPos;
	for (i = 0; i < sizeof(shipSize) / 4; i++)
		{
		sizeCheck = shipSize[i];
		orentation = flipACoin();
		if (orentation == 1)
			{
			j = 0;
			while ( j == 0)
				{
				firstPos = rand() % (10  - sizeCheck);
				secondPos = rand() % 10;
				for (k = 0; k < shipSize[i]; k++)
					{
					l = k + 1;
					if (arr[firstPos + k][secondPos] == '~')
						{
						if (l == shipSize[i])
							{
							for (p = 0; p < shipSize[i]; p++)
								{
								arr[firstPos + p][secondPos] = shipSymbols[i];
								}
							j++;
							}
						}
					else
						{
						k = 240962; // I ask my friend for a random
								    // Bigger than 5
						}
						
					}
				}
			}
		else
			{
			j = 0;
			while ( j == 0)
				{
				firstPos = rand() % (10  - sizeCheck);
				secondPos = rand() % 10;
				for (k = 0; k < shipSize[i]; k++)
					{
					l = k + 1;
					if (arr[secondPos][firstPos + k] == '~')
						{
						if (l == shipSize[i])
							{
							for (p = 0; p < shipSize[i]; p++)
								{
								arr[secondPos][firstPos + p] = shipSymbols[i];
								}
							j++;
							}
						}
					else
						{
						k = 240962; // I ask my friend for a random
							    // Bigger than 5
						}
						
					}
				}
			}
		}
	}
	
/*************************************************************
 * Function: Manually Place Ships         	
 * Date Created: 04/05/19                  	        
 * Date Last Modified: 04/05/19                       
 * Description: Allows the user to manually place the ships               	
 * Input parameters: An array	
 * Returns: A array with manually placed ships      	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/
void manuallyPlaceShips(char arr[][cols]){
	int i;
	int j;
	int k;
	int l;
	int p;
	string ship;
	int sizeOfShip;
	char charOfShip;
	int rowPlace;
	int colPlace;
	int orentation;
	cout << "Please enter in row then col with the first place";
	cout << " being the number you enter. The first row/column is 0";
	cout << " and the last one is 9.\n";
	for (i = 0; i < sizeof(shipSize) / 4; i++)
		{
		ship = shipNames[i];
		sizeOfShip = shipSize[i];
		charOfShip = shipSymbols[i];
		printArray(arr);
		cout << endl;
		cout << "Please enter the orentation of the ship.";
		cout << "0 for horizantal, 1 for vertical: ";
		cin >> orentation;
		j = 0;
		while (j == 0)
			{
			if (orentation != 1 && orentation != 0)
				{
				cout << "Please enter the orentation of the ship.";
				cout << "0 for horizantal, 1 for vertical: ";
				cin >> orentation;
				}
			else
				{
				if (orentation == 0)
					{
					cout << "Where would you like to place your " << ship;
					cout << ". It is " << sizeOfShip << " places long.\n";
					cout << "Row: ";
					cin >> rowPlace;
					cout << "Column: ";
					cin >> colPlace;
					for (k = 0; k < shipSize[i]; k++)
						{
						l = k + 1;
						if (arr[rowPlace][colPlace + k] == '~')
							{
							if (l == shipSize[i])
								{
								for (p = 0; p < shipSize[i]; p++)
									{
									arr[rowPlace][colPlace + p] = shipSymbols[i];
									}
								cout << endl;
								j++;
								}
							}
						else
							{
							k = 240962; // I ask my friend for a random
								    // Bigger than 5
							cout << "A ship cannot be placed there since there is another ship is in the way.";
							}
							
						}
					}
				else
					{
					cout << "Where would you like to place your " << ship;
					cout << ". It is " << sizeOfShip << " places long.\n";
					cout << "Row: ";
					cin >> rowPlace;
					cout << "Column: ";
					cin >> colPlace;
					for (k = 0; k < shipSize[i]; k++)
						{
						l = k + 1;
						if (arr[rowPlace + k][colPlace ] == '~')
							{
							if (l == shipSize[i])
								{
								for (p = 0; p < shipSize[i]; p++)
									{
									arr[rowPlace + p][colPlace] = shipSymbols[i];
									}
								cout << endl;
								j++;
								}
							}
						else
							{
							k = 240962; // I ask my friend for a random
								    // Bigger than 5
							cout << "A ship cannot be placed there since there is another ship is in the way.";
							}
							
						}
					}	
				}
			}
		}
	}

/*************************************************************
 * Function: Play Game        	
 * Date Created: 04/06/19                  	        
 * Date Last Modified: 04/07/19                       
 * Description: Plays the game of battleship               	
 * Input parameters: the solution arrays and shots fired arrays
 * 					 and player order	
 * Returns: Nothing      	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/	
		
void playGame(char P1SolutionArray [][cols],char P2SolutionArray [][cols],char shotFiredArray[][cols], char cpuShotsFired[][cols], int playerOrder){
	int i = 1;
	int j = 3;
	int soundEffect;
	int rowFire;
	int colFire;
	char rowFireChar;
	stats P1;
	stats P2;
	int P1ShipHit [] = {0, 0, 0, 0, 0};
	int P2ShipHit [] = {0, 0, 0, 0, 0};
	/*int P1ShotsFired = 0;
	int P1ShotsMissed = 0;
	int P1ShotsHit = 0;
	int P2ShotsFired = 0;
	int P2ShotsMissed = 0;
	int P2ShotsHit = 0;*/
	int winner;
	bool wrongArea;
	ofstream outputFile;
	while (P1.shotsHit != 17 && P2.shotsHit != 17)
		{
		if (playerOrder == 1)
			{
			system("clear");
			//cout << "P1 Shots: " << P1ShotsFired << endl;
			//cout << "P2 Shots: " << P2ShotsFired << endl;
			//cout << "CPU Row: " << rowFire << endl;
			//cout << "CPU Col: " << colFire << endl;
			cout << "Player 2 Board\n";
			printArray(shotFiredArray);
			cout << endl;
			cout << "Player 1 Board\n";
			printArray(P1SolutionArray);
			cout << endl;
			if (j == 0)
				{
				soundEffect = rand() % 2;
				if (soundEffect == 0)
					cout << "SPLISH!\n";
				if (soundEffect == 1)
					cout << "SPLOOSH!\n";
				}
			if (j == 1)
				cout << "KABUUM!\n";
			if (j == 2)
				cout << "You have already shot there.";
			if (j == 5)
				cout << "That does not fall in the correct region.\n";
			cout << "Where would you like to shoot?\n";
			cout << "Please enter the row: ";
			cin >> rowFireChar;
			rowFire = rowFireChar - 'A';
			cout << "Please enter the column: ";
			cin >> colFire;
			if (rowFire >= 0 && rowFire <=9)
				{
				if (shotFiredArray[rowFire][colFire] == '~')
					{
					P1.shotsFired++;
					if (P2SolutionArray [rowFire][colFire] == '~')
						{
						P1.shotsMissed++;
						shotFiredArray[rowFire][colFire] = 'm';
						j = 0;
						}
					else 
						{
						P1.shotsHit++;
						j = 1;
						if (P2SolutionArray [rowFire][colFire] == 'c')
							{
							cout << "KABUUM!\n";
							P1ShipHit[0]++;
							shotFiredArray [rowFire][colFire] = '*';
							if (P1ShipHit[0] == 5)
								scanArray('c', P2SolutionArray, shotFiredArray);
							}
						if (P2SolutionArray [rowFire][colFire] == 'b')
							{
							cout << "KABUUM!\n";
							P1ShipHit[1]++;
							shotFiredArray [rowFire][colFire] = '*';
							if (P1ShipHit[1] == 4)
								scanArray('b', P2SolutionArray, shotFiredArray);
							}
						if (P2SolutionArray [rowFire][colFire] == 'r')
							{
							cout << "KABUUM!\n";
							P1ShipHit[2]++;
							shotFiredArray [rowFire][colFire] = '*';
							if (P1ShipHit[2] == 3)
								scanArray('r', P2SolutionArray, shotFiredArray);
							}
						if (P2SolutionArray [rowFire][colFire] == 's')
							{
							cout << "KABUUM!\n";
							P1ShipHit[3]++;
							shotFiredArray [rowFire][colFire] = '*';
							if (P1ShipHit[3] == 3)
								scanArray('s', P2SolutionArray, shotFiredArray);
							}
						if (P2SolutionArray [rowFire][colFire] == 'd')
							{
							cout << "KABUUM!\n";
							P1ShipHit[4]++;
							shotFiredArray [rowFire][colFire] = '*';
							if (P1ShipHit[4] == 2)
								scanArray('d', P2SolutionArray, shotFiredArray);
							}
						}
					if (P1.shotsHit == 17)
						{
						cout << "Excellent vork, sailor! zyou deeds haff\nsuccessfully";
						cout << " protected zee peace on\nzis fair island! Vee are so";
						cout << " very proud!\nPlease take this Piece of Heart as a";
						cout << " sign of our gratitude.\n";
						winner = 1;
						} 
					playerOrder++;
					}
				else
					j = 2;	
				}
			else
				j = 5;
			}
		else if (playerOrder == 2)
			{
			system("clear");
			cout << "Player 2's turn.\n";
			printArray(cpuShotsFired);
			rowFire = rand() % 10;
			colFire = rand() % 10;
			//cout << "CPU Row: " << rowFire << endl;
			//cout << "CPU Col: " << colFire << endl;
			if (P1SolutionArray [rowFire][colFire] == '~')
				{
				P2.shotsFired++;
				playerOrder--;
				P2.shotsMissed++;
				soundEffect = rand() % 2;
				if (soundEffect == 0)
					cout << "SPLIISH!\n";
				if (soundEffect == 1)
					cout << "SPLOOSH!\n";
				P1SolutionArray [rowFire][colFire] = 'm';
				}
			else if (P1SolutionArray [rowFire][colFire] != 'm' && P1SolutionArray [rowFire][colFire] != '*')
				{
				P2.shotsFired++;
				playerOrder--;
				P2.shotsHit++;
				if (P1SolutionArray [rowFire][colFire] == 'c')
					{
					cout << "KABUUM!\n";
					P2ShipHit[0]++;
					P1SolutionArray [rowFire][colFire] = '*';
					}
				if (P1SolutionArray [rowFire][colFire] == 'b')
					{
					cout << "KABUUM!\n";
					P2ShipHit[1]++;
					P1SolutionArray [rowFire][colFire] = '*';
					}
				if (P1SolutionArray [rowFire][colFire] == 'r')
					{
					cout << "KABUUM!\n";
					P2ShipHit[2]++;
					P1SolutionArray [rowFire][colFire] = '*';
					}
				if (P1SolutionArray [rowFire][colFire] == 's')
					{
					cout << "KABUUM!\n";
					P2ShipHit[3]++;
					P1SolutionArray [rowFire][colFire] = '*';
					}
				if (P1SolutionArray [rowFire][colFire] == 'd')
					{
					cout << "KABUUM!\n";
					P2ShipHit[4]++;
					P1SolutionArray [rowFire][colFire] = '*';
					}
				}
			if (P2.shotsHit == 17)
				{
				cout << "You lost to a random number generator...\n";
				winner = 2;
				}
			}
		//else 
			//playerOrder = 2; // This is to fix a bug if the cpu shot at a spot it had already 
							 // shot at, it would cause an infite loop.
							 // I think I found the source of the bug but this should
							 // always correct it.
		}
	outputFile.open("battleship.log");
	outputFile << "\nPlayer 1 Stats\n";
	outputFile << "Player 1 shot " << P1.shotsFired << " shots.\n";
	outputFile << "Player 1 hit " << P1.shotsHit << " shots.\n";
	outputFile << "Player 1 missed " << P1.shotsMissed << " shots.\n";
	if (P1.shotsMissed == 0)
		{
		outputFile << "Player 1 had a 100% hit to miss ratio.\n";
		outputFile << "Hit or miss, I guess they never miss huh.\n";
		}
	else 
		{	
		outputFile << "Player 1 had a " << static_cast<double>(P1.shotsHit) / P1.shotsMissed * 100.0;
		outputFile << "% hit to miss ratio.\n";
		}
	outputFile << "\nPlayer 2 Stats\n";
	outputFile << "Player 2 shot " << P2.shotsFired << " shots.\n";
	outputFile << "Player 2 hit " << P2.shotsHit << " shots.\n";
	outputFile << "Player 2 missed " << P2.shotsMissed << " shots.\n";
	if (P1.shotsMissed == 0)
		{
		outputFile << "Player 2 had a 100% hit to miss ratio.\n";
		outputFile << "Hit or miss, I guess they never miss huh.\n";
		}
	else 
		{	
		outputFile << "Player 2 had a " << static_cast<double>(P2.shotsHit) / P2.shotsMissed * 100.0;
		outputFile << "% hit to miss ratio.\n";
		}
	outputFile << "\nWinner\n";
	if (winner == 1)
		outputFile << "Player 1 won.";
	else if (winner == 2)
		outputFile << "Player 2 won.";
	outputFile.close();
	}

/*************************************************************
 * Function: Scan Array           	
 * Date Created: 04/05/19                  	        
 * Date Last Modified: 04/05/19                       
 * Description: Scan an array and replace with * with shot ships               	
 * Input parameters: the char it is checking for and a shots fired
 					 and solution array
 * Returns: solution array filled with the chars of sunk ships       	
 * Pre: Nothing.      	
 * Post:      
 *************************************************************/			
void scanArray(char checkChar, char P2SolutionArray[][cols], char shotFiredArray[][cols]){
	int i;
	int j;
	for (i = 0; i < rows; i++)
		{
		for (j = 0; j < cols; j++)
			{
			if (P2SolutionArray[i][j] == checkChar)
				shotFiredArray[i][j] = checkChar;
			}
		}
	}

/*************************************************************
 * Function: Games Rules           	
 * Date Created: 04/06/19                  	        
 * Date Last Modified: 04/06/19                       
 * Description: outputs the game rules               	
 * Input parameters: nothing
 * Returns: nothing     	
 * Pre: Nothing.      	
 * Post: Outputed game rules   
 *************************************************************/
void gameRules(){
	cout << "**** Welcome to Battleship! ****\n";
	cout << "Rules of the Game:\n";
	cout << "1. This is a two player game.\n";
	cout << "2. Player 1 is you and Player 2 is the computer.\n";
	cout << "3. After the turn order is \ndecided, each player ";
	cout << "takes turns guessing a location on the board\n";
	cout << "if the player guesses right, you will be told,\n";
	cout << "but the ship type wont be revealed ";
	cout << "until you sink it.\n";
	cout << "Press any key to continue.";
	cin.ignore();
	system("clear");
	}
		
		
		
