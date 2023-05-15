#include <stdlib.h>
#include "main.h"
/**
 * count_word - Function counts the total number of words inthe inputted string
 * @s: String to be inputted and checked
 * Return: Total number of words
 */
int count_word(char *s)
{
	int identify, d, v;

	flag = 0;
	v = 0;
	for (d = 0; s[d] != '\0'; d++)
	{
		if (s[d] == ' ')
			identify = 0;
		else if (identify == 0)
		{
			identify = 1;
			v++;
		}
	}
	return (v);
}
/**
 * **strtow - A function that splits a string into words
 * @str: String to be split
 * Return: Pointer to an array of strings on Success, otherwise NULL on Error
 */
char **strtow(char *str)
{
	char **pattern, *sub;
	int j, l = 0, len = 0, total_words, d = 0, begin, finish;

	while (*(str + len))
		len++;
	total_words = count_word(str);
	if (total_words == 0)
		return (NULL);
	pattern = (char **) malloc(sizeof(char *) * (total_words + 1));

	if (pattern == NULL)
		return (NULL);
	for (j = 0; j <= len; j++)
	{
		if (str[j] == ' ' || str[j] == '\0')
		{
			if (d)
			{
				finish = j;

				sub = (char *) malloc(sizeof(char) * (d + 1));

				if (sub == NULL)
					return (NULL);
				while (begin < finish)
					*sub++ = str[begin++];
				*sub = '\0';

				pattern[l] = sub - d;

				l++;

				d = 0;
			}
		}
		else if (d++ == 0)
			begin = j;
	}
	pattern[l] = NULL;
	return (pattern);
}
