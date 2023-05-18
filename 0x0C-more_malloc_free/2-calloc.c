#include <stdlib.h>
#include "main.h"

/**
 * *_memset - Function to populate memory with a constant byte
 * @s: memory area to be populated
 * @b: char to be copied
 * @n: number of times for b to be copied
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
	{
		s[j] = b;
	}
	return (s);
}

/**
 * *_calloc - Function allocates memory for an array, using malloc
 * @nmemb: Number of array element
 * @size: Each element size
 * Return: Pointer allocated to memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmemb);

	if (ptr == NULL)
		return (NULL);
	_memset(ptr, 0, nmemb * size);
	return (ptr);
}
