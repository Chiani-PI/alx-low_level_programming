#include <stdlib.h>
#include "main.h"
/**
 * *malloc_checked - Function allocates memory using malloc
 * @b: Size of bytes to be allocated
 * Return: A pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);
	return (ptr);
}
