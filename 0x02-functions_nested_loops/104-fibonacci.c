#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
unsigned int i, count;
unsigned long int a = 1, b = 2, c;
count = 2;
printf("%lu, %lu", a, b);
for (i = 3; i <= 98; i++)
{
c = a + b;
printf(", %lu", c);
a = b;
b = c;
count++;
}
printf("\n");
return (0);
}
