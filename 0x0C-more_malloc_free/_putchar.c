#include "main.h"
#include <unistd.h>
/**
 * _putchar - A function that creates an array of chars,
 * and initializes it with a specific char
 * @c: The character to be  printed
 * Return: On success 1, otherwise -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
