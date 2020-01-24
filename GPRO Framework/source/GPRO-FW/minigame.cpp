#include <iostream>
#include <ctime>
#include "GPRO-FW/minigame.h"

void runGame()
{
	srand(time(NULL));
	char yn;
	int turns, num, guess;

	do
	{
		//resets the turn count;
		turns = 5;
		//sets the random number
		num = rand() % 100 + 1;

		//welcome player
		std::cout << "Welcome to Number Guess" << std::endl;
		std::cout << "The goal of the game is to guess a number between 1-100" << std::endl;
		std::cout << "The number has been selected" << std::endl;

		//number guessing loop
		do
		{
			std::cout << "Remaining turns: " << turns << std::endl;
			std::cout << "What is your guess?" << std::endl;
			std::cin >> guess;

			if (guess < 1 || guess > 100)
			{
				std::cout << "Please input a number 1-100" << std::endl;
			}
			else
			{
				turns--;

				if (guess > num)
				{
					std::cout << "Lower" << std::endl;
				}
				else if (guess < num)
				{
					std::cout << "Higher" << std::endl;
				}
			}
		} while (turns > 0 && guess != num);

		//if the player won or lost
		if (guess == num)
		{
			std::cout << "Congratulations!" << std::endl;
		}
		else
		{
			std::cout << "Too bad, the number was " << num << std::endl;
		}

		//asks the player if they want to play again
		do
		{
			std::cout << "Would you like to play again? (y/n)" << std::endl;
			std::cin.get(yn);
			std::cin.ignore();

			if (yn != 'y' && yn != 'n')
			{
				std::cout << "Please input 'y' for yes or 'n' for no" << std::endl;
			}
		} while (yn != 'y' && yn != 'n');
	} while (yn == 'y');

	std::cout << "Thanks for playing! Goodbye" << std::endl;
}