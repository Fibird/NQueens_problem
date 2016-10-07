// NQueens_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

bool isok(int row, int width, int *queens);
void printBoard(int *queens, int width);
void Nqueens(int deepth, int width, int *queens);
void initQueens(int *queens, int width);

int main()
{
	int width;
	int *queens;
	printf("Enter the width of chessboard: ");
	scanf_s("%d", &width);

	queens = (int *)malloc(width * sizeof(int));
	Nqueens(0, width, queens);
    return 0;
}

bool isok(int row, int width, int *queens)
{
	int p = width - row;
	for (int i = 0; i < row; i++)
	{
		if ((queens[i] + (row - i)) <= width)
		{
			p--;
		}
		else if ((queens[i] + (row + i)) >= 0)
		{
			p--;
		}
	}
	if (p > 0)
		return true;
	else
		return false;
}

void printBoard(int * queens, int width)
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
	if (deepth > width)
	{
		printBoard(queens, width);
	}
	else
	{
		for (int i = 0; i < width; i++)
		{
			queens[deepth] = i;
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

