#include "main.h"

/**
 * get_endianness - Function checks the endianness
 * i.e. the order in which a sequence of bytes is stored in computer memory,
 * big or small
 * Return: 0 for big endian, 1 for little endian
 */
int get_endianness(void)
{
	unsigned int j = 1;
	char *c = (char *) &j;

	return (*c);
}
