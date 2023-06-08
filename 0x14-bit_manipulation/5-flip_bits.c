#include "main.h"

/**
 * flip_bits - Function counts and returns the number of bits
 * that we would need to flip to get from one number to another
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: The number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int j, tally = 0;
	unsigned long int present;
	unsigned long int total = n ^ m;

	for (j = 63; j >= 0; j--)
	{
		present = total >> j;
		if (present & 1)
			tally++;
	}
	return (tally);
}
