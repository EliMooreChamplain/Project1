// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
<<<<<<< HEAD:GPRO Framework/source/GPRO-FW-Launcher/GPRO-FW-Launcher_main.c
//

#include <stdio.h>


int launchTicTacToe();
int launchCheckers();

int main()
{
	int choice = 0;
	do
	{
		printf("Press 1 for Tic-Tac-Toe or 2 for Checkers: ");
		scanf("%i", &choice);
	} while (choice != 1 && choice != 2);

	if (choice == 1)
	{
		launchTicTacToe();
	}
	else
	{
		launchCheckers();
	}
}
=======

#include "GPRO-FW/minigame.h"

int main()
{
	runGame();

	return 0;
}
>>>>>>> bae46f3514ab7ee124bb40772a1574e47ed23541:GPRO Framework/source/GPRO-FW-Launcher/GPRO-FW-Launcher_main.cpp
