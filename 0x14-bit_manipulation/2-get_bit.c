#include "main.h"

/**
 * get_bit - Function returns the val of a bit at a givn index
 * @n: The number to be searched
 * @index: The bit index
 *
 * Return: index (value of the bit at index), otherwise -1 (error)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bitvalue;

	if (index > 63)
		return (-1);

	bitvalue = (n >> index) & 1;

	return (bitvalue);
}
