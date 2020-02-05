// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
