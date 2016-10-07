// NQueens_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

bool isok(int row, int width, const int *queens);
void printBoard(const int *queens, int width);
void Nqueens(int deepth, int width, int *queens);
void initQueens(int *queens, int width);
bool checkPos(int row, int pos, const int *queens);

int main()
{
	int width;
	int *queens;
	printf("Enter the width of chessboard: ");
	scanf_s("%d", &width);

	queens = (int *)malloc(width * sizeof(int));
	initQueens(queens, width);

	Nqueens(0, width, queens);
    return 0;
}

bool isok(int row, int width, const int *queens)
{
	int p = width - row - 1;
	for (int i = 0; i <= row; i++)
	{
		if ((queens[i] + (row + 1 - i)) <= (width - 1))
		{
			p--;
		}
		else if ((queens[i] - (row + 1 - i)) >= 0)
		{
			p--;
		}
	}
	if (p > 0)
		return true;
	else
		return false;
}

void printBoard(const int * queens, int width)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == queens[i])
				printf("Q");
			else
				printf(".");
		}
		printf("\n");
	}
}

void Nqueens(int deepth, int width, int *queens)
{
	if (deepth >= width - 1)
	{
		printBoard(queens, width);
	}
	else
	{
		for (int i = 0; i < width; i++)
		{
			if (checkPos(i, deepth, queens))
				queens[deepth] = i;
			else
				continue;
			if (isok(deepth, width, queens))
				Nqueens(++deepth, width, queens);
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
		if ((queens[i] + (row + 1 - i)) == pos)
		{
			return false;
		}
		else if ((queens[i] - (row + 1 - i)) == pos)
		{
			return false;
		}
	}
	return true;
}

