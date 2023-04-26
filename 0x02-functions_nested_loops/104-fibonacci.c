#include <stdio.h>
/**
 * main -  prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 * Return: Always 0
 */
int main(void)
{
int a;
unsigned long int i;
unsigned long int pre = 1;
unsigned long int post = 2;
unsigned long int i = 1000000000;
unsigned long int pre1;
unsigned long int pre2;
unsigned long int post1;
unsigned long int post;
printf("%lu", pre);
for (i = 1; i < 91; i++)
{
printf(", %lu", post);
post += pre;
pre = post - pre;
}
pre1 = (pre / l);
pre2 = (pre % l);
post1 = (post / l);
post2 = (post % l);
for (i = 1; i < 91; i++)
{
printf(", %lu", post1 + (post2 / l));
printf("%lu", post2 % l);
post1 = post1 + pre1;
pre1 = post1 - pre1;
post2 = post2 + pre2;
pre2 = post2 - pre2;
}
printf("\n");
return (0);
}
