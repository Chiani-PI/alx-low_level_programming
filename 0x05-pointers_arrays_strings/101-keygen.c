#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 100

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme
 * Return: Always 0 (Success)
 */

int main(void)
{
	int pass[MAX_LEN];
	int i, sum, n;

	sum = 0;

	srand(time(NULL));

	for (i = 0; i < MAX_LEN - 1; i++)
	{
		pass[i] = rand() % 78 + 48;
		// Generates a random ASCII character
		// between '0' (48) and 'z' (122)
		sum += pass[i];

		putchar(pass[i]);
	}

	// Calculate the last character to make the sum of all characters
	// equal to 2772

	n = 2772 - sum;
	pass[MAX_LEN - 1] = n;

	putchar(n);

	return (0);
}
