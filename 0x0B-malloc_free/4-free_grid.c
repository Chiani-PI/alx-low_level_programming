#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * free_grid - A function that frees a 2 dimensional grid
 * previously created by your alloc_grid function
 * @grid: 2 dimentional grid
 * @height: Height of grid
 * Description: Will free the  memory of grid
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int j;

	for (j = 0; j < height; j++)
	{
		free(grid[j]);
	}
	free(grid);
}
