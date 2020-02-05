
#include <stdio.h>
#include <stdbool.h>


//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_CHECKERS_PLAYERS					2
#define GS_CHECKERS_BOARD_WIDTH				8
#define GS_CHECKERS_BOARD_HEIGHT			8

enum gs_checkers_space_state
{
	// invalid space state
	gs_checkers_space_invalid = -1,

	// states visible to both players
	gs_checkers_space_open,			// space is open
	gs_checkers_space_black,		// space is occupied by black piece
	gs_checkers_space_white,		// space is occupied by white piece
	gs_checkers_space_black_king,	// space is occupied by black king piece
	gs_checkers_space_white_king,	// space is occupied by white king piece
};
#ifndef __cplusplus
typedef		enum gs_checkers_space_state	gs_checkers_space_state;
#endif	// !__cplusplus

// checkers game state
typedef		unsigned char					gs_checkers_index;
typedef		gs_checkers_space_state			gs_checkers[GS_CHECKERS_BOARD_WIDTH][GS_CHECKERS_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,w,h)			(x < w && y < h)
#define GS_CHECKERS_VALID(x,y)					GS_VALIDATE_COORDINATE(x,y,GS_CHECKERS_BOARD_WIDTH,GS_CHECKERS_BOARD_HEIGHT)


inline gs_checkers_space_state gs_checkers_getSpaceState(gs_checkers const game, gs_checkers_index const xpos, gs_checkers_index const ypos)
{
	if (GS_CHECKERS_VALID(xpos, ypos))
		return (game[xpos][ypos]);
	return gs_checkers_space_invalid;
}

inline gs_checkers_space_state gs_checkers_setSpaceState(gs_checkers game, gs_checkers_space_state const state, gs_checkers_index const xpos, gs_checkers_index const ypos)
{
	if (GS_CHECKERS_VALID(xpos, ypos))
		return (game[xpos][ypos] = state);
	return gs_checkers_space_invalid;
}

inline gs_checkers_index gs_checkers_reset(gs_checkers game)
{
	gs_checkers_index xpos, ypos, total;
	for (xpos = 0; xpos < GS_CHECKERS_BOARD_WIDTH; ++xpos)
		for (ypos = 0; ypos < GS_CHECKERS_BOARD_HEIGHT; ++ypos)
			game[xpos][ypos] = gs_checkers_space_open;
	total = (xpos * ypos);
	for (xpos = 0; xpos < 3; ++xpos)
		for (ypos = xpos % 2; ypos < GS_CHECKERS_BOARD_HEIGHT; ypos += 2)
		{
			game[xpos][GS_CHECKERS_BOARD_HEIGHT - ypos - 1] = gs_checkers_space_black;
			game[GS_CHECKERS_BOARD_WIDTH - xpos - 1][ypos] = gs_checkers_space_white;
		}
	return total;
}

void showBoard(gs_checkers game)
{
	system("CLS");
	printf("  ");
	for (int i = 1; i < GS_CHECKERS_BOARD_WIDTH + 1; i++)
	{
		printf("%i", i);
		printf(" ");
	}
	printf("\n");
	for (int i = 0; i < GS_CHECKERS_BOARD_HEIGHT; i++)
	{
		printf("%i", i + 1);
		printf(" ");
		for (int j = 0; j < GS_CHECKERS_BOARD_WIDTH; j++)
		{
			if(game[j][i] == gs_checkers_space_open)
			{
				printf("# ");
			}
			else if(game[j][i] == gs_checkers_space_black)
			{
				printf("x ");
			}
			else if(game[j][i] == gs_checkers_space_white)
			{
				printf("o ");
			}
			
		}
		printf("\n");
	}
}

void movePieces(gs_checkers game)
{
	int prevPosX, xCoord, yCoord, prevPosY, newPosX, newPosY;
	bool isValid;
	do
	{
		do
		{
			isValid = true;
			printf("Piece: \n");
			printf("Enter an x coordinate: ");
			
			scanf("%i", &xCoord);
			printf("\nEnter a y coordinate: ");
			
			scanf("%i", &yCoord);

			prevPosX = xCoord - 1;
			prevPosY = yCoord - 1;
			if (game[prevPosX][prevPosY] == gs_checkers_space_open)
			{
				isValid = false;
				printf("That space is empty\n");
			}
			if (game[prevPosX,prevPosY] == gs_checkers_space_white)
			{
				printf("That is the enemy's piece\n");
			}

		} while (!isValid);

		printf("To: \n");
		printf("Enter an x coordinate: ");
		scanf("%i", &xCoord);
		printf("\nEnter a y coordinate: ");
		scanf("%i", &yCoord);

		newPosX = xCoord - 1;
		newPosY = yCoord - 1;
		if (!(prevPosX == newPosX && prevPosY == newPosY))//If its not the same position
		{
			if (abs(newPosY - prevPosY) == abs(newPosX - prevPosX))//If the player is moving diagonally
			{
				if (newPosX - prevPosX > 0)//If the player is moving forward
				{
					if (game[newPosX][newPosY] == gs_checkers_space_open)//If the player is not going into an occupied space
					{
						if (abs(newPosX - prevPosX) == 1 && abs(newPosY - prevPosY) == 1)//if the player is only moving one space
						{
							isValid = true;//*****************************************TOP LEVEL MOVING
						}
						else
						{
							if (
								game[newPosX - ((newPosY - prevPosY) / (newPosX - prevPosX))][newPosY - ((newPosY - prevPosY) / (newPosX - prevPosX))] == gs_checkers_space_white &&
								newPosX - (2 * (newPosY - prevPosY) / (newPosX - prevPosX)) == prevPosX &&
								newPosY - (2 * (newPosY - prevPosY) / (newPosX - prevPosX)) == prevPosY
								)//If the player is jumping correctly
							{
								isValid = true;//*****************************************TOP LEVEL JUMPING
								game[newPosX - ((newPosY - prevPosY) / (newPosX - prevPosX))][newPosY - ((newPosY - prevPosY) / (newPosX - prevPosX))] = gs_checkers_space_open;
							}
							else
							{
								printf("You can only move one space\n");
								isValid = false;
							}
						}
					}
					else
					{

						printf("Can't move into an occupied space\n");
						isValid = false;
					}
				}
				else
				{
					printf("You need to move forward\n");
					isValid = false;
				}
			}
			else
			{
				printf("You need to move diagonally\n");
				isValid = false;
			}
		}
		else
		{
			printf("That's the same position you started in\n");
			isValid = false;
		}
	} while (!isValid);
	game[newPosX][newPosY] = game[prevPosX][prevPosY];//Move to space
	game[prevPosX][prevPosY] = gs_checkers_space_open;
}


//-----------------------------------------------------------------------------
// DEFINITIONS

int launchCheckers()
{
	gs_checkers game = { 0 };

	gs_checkers_reset(game);

	while (true)
	{
		showBoard(game);
		movePieces(game);
	}
	

	return 0;
}


//-----------------------------------------------------------------------------
