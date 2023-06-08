#include "main.h"
#include <unistd.h>
/**
 * _putchar - This function will write the char c to stdout
 * @c: The character that is to be printed
 *
 * Return: 1 (success), otherwise -1 is then errno is set accordingly
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
