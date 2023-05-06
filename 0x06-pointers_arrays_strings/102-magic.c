#include <stdio.h>
/**
 * main - Program prints a[2] = 98, followed by a new line
 * Return: Always 0 (Succes)
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	/*
	 * write your line of code here...
	 * Remember - u aren't allowed to use a - u aren't allowed to modify p;
	 * -only 1 statmnt -u aren't alwd 2 code anythn else thn ths ln of code
	 */
	*(p + 5) = 98;

	/* ...so that this prints 98\n */
	printf("a[2] = %d\n", a[2]);
	return (0);
}
