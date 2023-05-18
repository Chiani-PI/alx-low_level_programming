#include <stdlib.h>
#include "main.h"
/**
 * *array_range - Function that creates an array of integers
 * @min: minimum range of stored values
 * @max: maximum range of stored values and total number of elements
 * Return: pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *ptr;

	int j, size;

	if (min > max)
		return (NULL);
	size = max - min + 1;
	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
		return (NULL);
	for (j = 0; min <= max; j++)
		ptr[j] = min++;
	return (ptr);
}
