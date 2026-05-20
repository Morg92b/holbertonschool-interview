#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 grid
 * @grid: grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");

			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - checks if grid is stable
 * @grid: grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}

	return (1);
}

/**
 * topple - applies one toppling round
 * @grid: grid to modify
 */
void topple(int grid[3][3])
{
	int temp[3][3];
	int i, j;

	/* copy grid */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			temp[i][j] = grid[i][j];
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (temp[i][j] > 3)
			{
				grid[i][j] -= 4;

				if (i > 0)
					grid[i - 1][j] += 1;

				if (i < 2)
					grid[i + 1][j] += 1;

				if (j > 0)
					grid[i][j - 1] += 1;

				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - sums two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* addition */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	/* stabilize */
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
