#include <unistd.h>
/**
 * main - C program that prints a one line output  followed by a new line, to the standard error.
 * Return: 1
 */
int main(void)
{
char *quote = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
write(2, quote, 59);
return 1;
}
