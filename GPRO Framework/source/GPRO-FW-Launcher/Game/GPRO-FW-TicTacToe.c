
#include <stdio.h>


//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_TICTACTOE_PLAYERS					2
#define GS_TICTACTOE_BOARD_WIDTH				3
#define GS_TICTACTOE_BOARD_HEIGHT				3

enum gs_tictactoe_space_state
{
	// invalid space state
	gs_tictactoe_space_invalid = -1,

	// states visible to both players
	gs_tictactoe_space_open,	// space is open
	gs_tictactoe_space_o,		// space is taken by O player
	gs_tictactoe_space_x,		// space is taken by X player
};
#ifndef __cplusplus
typedef		enum gs_tictactoe_space_state		gs_tictactoe_space_state;
#endif	// !__cplusplus

// tic-tac-toe game state
typedef		unsigned char						gs_tictactoe_index;
typedef		gs_tictactoe_space_state			gs_tictactoe[GS_TICTACTOE_BOARD_WIDTH][GS_TICTACTOE_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,w,h)			(x < w && y < h)
#define GS_TICTACTOE_VALID(x,y)					GS_VALIDATE_COORDINATE(x,y,GS_TICTACTOE_BOARD_WIDTH,GS_TICTACTOE_BOARD_HEIGHT)


inline gs_tictactoe_space_state gs_tictactoe_getSpaceState(gs_tictactoe const game, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos]);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_space_state gs_tictactoe_setSpaceState(gs_tictactoe game, gs_tictactoe_space_state const state, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos] = state);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_index gs_tictactoe_reset(gs_tictactoe game)
{
	gs_tictactoe_index xpos, ypos, total;
	for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos)
		for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos)
			game[xpos][ypos] = gs_tictactoe_space_open;
	total = (xpos * ypos);
	return total;
}

void displayBoard(gs_tictactoe game)
{
	system("CLS");

	printf("  1  2  3  X\n");

	gs_tictactoe_index xpos, ypos;
	for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos)
	{
		printf("%i", ypos + 1);
		for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos)
		{
			if (gs_tictactoe_getSpaceState(game, xpos, ypos) == gs_tictactoe_space_x)
			{
				printf(" X ");
			}
			if (gs_tictactoe_getSpaceState(game, xpos, ypos) == gs_tictactoe_space_o)
			{
				printf(" O ");
			}
			if (gs_tictactoe_getSpaceState(game, xpos, ypos) == gs_tictactoe_space_open)
			{
				printf(" _ ");
			}
		}
		printf("\n");
	}
	printf("Y\n");
}

void getInput(gs_tictactoe game, char turn)
{
	int allowed = 0, xCoord, yCoord;
	do
	{
		do
		{
			printf("Enter an x coordinate: ");
			scanf("%i", &xCoord);

			if (xCoord > 3 || xCoord < 1)
			{
				printf("Please input a value 1-3\n");
			}
		} while (xCoord > 3 || xCoord < 1);

		do
		{
			printf("\nEnter a y coordinate: ");
			scanf("%i", &yCoord);

			if (yCoord > 3 || yCoord < 1)
			{
				printf("Please input a value 1-3\n");
			}
		} while (yCoord > 3 || xCoord < 1);

		if (gs_tictactoe_getSpaceState(game, xCoord - 1, yCoord - 1) != gs_tictactoe_space_open)
		{
			printf("That space is already full\n");
		}
		else
		{
			if (turn == 'x')
			{
				gs_tictactoe_setSpaceState(game, gs_tictactoe_space_x, xCoord - 1, yCoord - 1);
			}
			else
			{
				gs_tictactoe_setSpaceState(game, gs_tictactoe_space_o, xCoord - 1, yCoord - 1);
			}
			allowed = 1;
		}
	} while (allowed == 0);
}

int checkWin(game)
{
	gs_tictactoe_index xpos, ypos;
	return 0;
}


//----------------------------------------------------------------------------
// DEFINITIONS

int launchTicTacToe()
{
	gs_tictactoe game = { 0 };

	gs_tictactoe_reset(game);

	displayBoard(game);

	int turn = 1, win = 0;
	char player;


	while (turn < 10 && win == 0)
	{
		if (turn % 2 == 0)
		{
			player = 'o';
			printf("O's turn\n");
		}
		else
		{
			player = 'x';
			printf("X's turn\n");
		}

		getInput(game, player);
		displayBoard(game);

		if (turn > 4)
		{
			win = checkWin(game);
		}

		++turn;
	}

	printf("Congratulations, you won!\n");

	return 0;
}




//-----------------------------------------------------------------------------
