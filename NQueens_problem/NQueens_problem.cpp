// NQueens_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
// Count the number of soltuion
static int count = 0;
// Prints the solution chessboard
void printBoard(const int *queens, int width);
// Solves the problem by recursive method
void Nqueens(int depth, int width, int *queens);
// Inits the array queen
void initQueens(int *queens, int width);
// Checks whether there is valid position
bool checkPos(int row, int pos, const int *queens);

int main()
{
	int width;
	int *queens;
	printf_s("Enter the width of chessboard: ");
	scanf_s("%d", &width);

	queens = (int *)malloc(width * sizeof(int));
	initQueens(queens, width);

	Nqueens(0, width, queens);
    return 0;
}

void printBoard(const int * queens, int width)
{
	count++;
	printf_s("----solution #%d----\n", count);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == queens[i])
				printf_s("Q");
			else
				printf_s(".");
		}
		printf_s("\n");
	}
}

void Nqueens(int depth, int width, int *queens)
{
	if (depth >= width)
	{
		printBoard(queens, width);
	}
	else
	{
		for (int i = 0; i < width; i++)
		{
			if (checkPos(depth, i, queens))
			{
				queens[depth] = i;
				Nqueens(depth + 1, width, queens);
			}	
		}
	}
}

void initQueens(int * queens, int width)
{
	for (int i = 0; i < width; i++)
		queens[i] = -1;
}

bool checkPos(int row, int pos, const int *queens)
{
	for (int i = 0; i < row; i++)
	{
		// Checks diagonal positions
		if ((queens[i] + (row - i)) == pos || (queens[i] - (row - i)) == pos)
		{
			return false;
		}
		// Checks column positions
		else if (queens[i] == pos)
		{
			return false;
		}
	}
	return true;
}

