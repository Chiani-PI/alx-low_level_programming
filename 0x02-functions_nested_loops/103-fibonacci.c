#include <stdio.h>
/**
 * main -  prints the sum of the terms with even values,
 * followed by a new line.
 * Return: Always 0
 */
int main(void)
{
int a;
unsigned long int b, c, next, sum;
b = 1;
c = 2;
sum = 0;
for (a = 0; a <= 33; ++a)
{
if (b < 4000000 && (j % 2) == 0)
{
sum = sum + b;
}
next = b + c;
b = c;
c = next;
}
printf("%lu\n", sum);
return (0);
}
