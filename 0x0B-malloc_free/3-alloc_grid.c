#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - Function returns a pointer to a 2 dimensional array of integers
 * @width: Inputted width
 * @height: Inputted height
 * Return: A pointer to 2 dimentional array on success, NULL on failure.
 */
int **alloc_grid(int width, int height)
{
	int **ret;
	int a, b;

	if (width <= 0 || height <= 0)
		return (NULL);
	ret = malloc(sizeof(int *) * height);

	if (ret == NULL)
		return (NULL);
	for (a = 0; a < height; a++)
	{
		ret[a] = malloc(sizeof(int) * width);

		if (ret[a] == NULL)
		{
			for (; a >= 0; a--)
			free(ret[a]);

			free(ret);
			return (NULL);
		}
	}
	for (a = 0; a < height; a++)
	{
		for (b = 0; b < width; b++)
		ret[a][b] = 0;
	}
	return (ret);
}
