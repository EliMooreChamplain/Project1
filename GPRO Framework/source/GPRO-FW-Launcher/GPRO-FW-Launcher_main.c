// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

int launchTicTacToe();
int launchCheckers();

int main()
{
	char game;
	do
	{
		printf("Type 1 to play Tic-Tac-Toe or 2 to play Checkers");
		scanf("%c", game);
		system("CLS");
	} while (game != '1' && game != '2');

	if (game == 1)
	{
		launchTicTacToe();
	}
	else
	{
		launchCheckers();
	}
}