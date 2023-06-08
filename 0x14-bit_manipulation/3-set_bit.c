#include "main.h"

/**
 * set_bit - Function sets the val of a bit to 1 at a given indx
 * @n: The pointer to the bit number that is to be changed
 * @index: index of the bit to set to 1
 *
 * Return: 1 on success, -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
