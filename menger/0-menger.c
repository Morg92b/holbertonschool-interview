#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_hole - Checks if a position is part of a hole
 * @x: x position
 * @y: y position
 *
 * Return: 1 if it is a hole, 0 otherwise
 */
int is_hole(int x, int y)
{
	int result;

	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);

		x /= 3;
		y /= 3;
	}

	result = 0;
	return (result);
}

/**
 * menger - Draws a 2D Menger sponge
 * @level: level of the Menger sponge
 */
void menger(int level)
{
	int size;
	int x, y;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_hole(x, y))
				printf(" ");
			else
				printf("#");
		}

		printf("\n");
	}
}
