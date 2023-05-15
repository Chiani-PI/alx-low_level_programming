#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - A function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * @str: char
 * Return: 0 (success)
 */
char *_strdup(char *str)
{
	char *bbb;
	int j, s = 0;

	if (str == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\0')
		j++;
	bbb = malloc(sizeof(char) * (j + 1));
	if (bbb == NULL)
		return (NULL);
	for (s = 0; str[s]; s++)
		bbb[s] = str[s];
	return (bbb);
}
