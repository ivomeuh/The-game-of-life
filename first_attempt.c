#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void initM(int M[16][16])
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 16)
	{
		while (y < 16)
		{
			M[x][y] = 0;
			y++;
		}
		y = 0;
		x++;
	}
}

void printM(int M[16][16])
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 16)
	{
		while (y < 16)
		{
			printf("%d", M[x][y]);
			y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
	printf("\n");
}

int countAliveN(int M[16][16], int x, int y, int aliveN)
{
	//printf("%d ", aliveN);
	if (M[x - 1][y] == 1 && (x - 1) >= 0)
	{
		aliveN++;
	}
	if (M[x + 1][y] == 1 && (x + 1) < 16)
	{
		aliveN++;
	}
	if (M[x][y - 1] == 1 && (y - 1) >= 0)
	{
		aliveN++;
	}
	if (M[x][y + 1] == 1 && (y + 1) < 16)
	{
		aliveN++;
	}
	if (M[x - 1][y - 1] == 1 && (x - 1) >= 0 && (y - 1) >= 0)
	{
		aliveN++;
	}
	if (M[x + 1][y + 1] == 1 && (x + 1) < 16 && (y + 1) < 16)
	{
		aliveN++;
	}
	if (M[x + 1][y - 1] == 1 && (x + 1) < 16 && (y - 1) >= 0)
	{
		aliveN++;
	}
	if (M[x - 1][y + 1] == 1 && (x - 1) >= 0 && (y + 1) < 16)
	{
		aliveN++;
	}
	//printf("%i\n", aliveN);
	return(aliveN);
}

void transferFromNewM(int M[16][16], int newM[16][16])
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (x < 16)
	{
		while (y < 16)
		{
			M[x][y] = newM[x][y];
			y++;
		}
		y = 0;
		x++;
	}
}

void transferFromM(int M[16][16], int newM[16][16])
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (x < 16)
	{
		while (y < 16)
		{
			newM[x][y] = M[x][y];
			y++;
		}
		y = 0;
		x++;
	}
}

void modifyM(int M[16][16], int newM[16][16])
{
	int x;
	int y;
	int aliveN; //aliveNeighbour
	
	x = 1;
	y = 1;

	while (x < 15)
	{
		while (y < 15)
		{
			aliveN = 0;
			aliveN = countAliveN(M, x, y, aliveN);
			if (M[x][y] == 1 && aliveN > 3 && aliveN < 9)
			{
				newM[x][y] = 0;
			}
			else if (M[x][y] == 1 && aliveN == 0 || M[x][y] == 1 && aliveN == 1)
			{
				newM[x][y] = 0;
			}
			else if (M[x][y] == 0 && aliveN == 3)
			{
				newM[x][y] = 1;
			}
			y++;
		}
		y = 1;
		x++;
	}
	transferFromNewM(M, newM);
	printM(M);
}

int main()
{
	int M[16][16];
	int newM[16][16];

	initM(M);
	initM(newM);

	M[8][7] = 1;
	M[8][8] = 1;
	M[8][9] = 1;

	transferFromM(M, newM);
	printM(M);

	while (1 == 1)
	{
		modifyM(M, newM);
		sleep(2);
	}

	return(0);
}
