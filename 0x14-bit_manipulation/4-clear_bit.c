#include "main.h"

/**
 * clear_bit - Function sets the val of a bit to 0 at a givn indx
 * @n: The pointer to the number that is to be changed
 * @index: The index of the bit that is to be cleared
 *
 * Return: 1 on success, otherwise -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = (~(1UL << index) & *n);
	return (1);
}
