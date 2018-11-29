// BLUE_CHAMBER.cpp : This file contains the 'main' function. Program execution begins and ends there.
// CODED BY JOHN WADE MILLER ON 11/10/2018
// BASED ON THE BLUE CHAMBER GAME BY TOSHIMITSU TAKAGI


#include "GAMEINTERACTION.h"

int main()
{
	bool gameCont = true; // repeats the while loop while its true
	tutorial(); // calls the tutorial function instructing you on how to play
	while (gameCont)
	{
		gameCont = gamePlay(); // calls the gameplay function
	}

}


