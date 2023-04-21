#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - This program prints the alphabet except q and e in lowercase, followed by a new line.
 * Return: Always 0 (Success)
 */
int main(void)
{
int a;
for (a = 97; a < 123; a++)
{
if (a != 101 && a != 113)
{
putchar(a);
}
}
putchar('\n');
return (0);
}
