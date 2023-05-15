#include "main.h"
#include <stdlib.h>
/**
 * argstostr - A  function that concatenates all the arguments of your program
 * @ac: Inputted int
 * @av: Double pointer array
 * Return: 0 on Success, otherwise NULL
 */
char *argstostr(int ac, char **av)
{
	int j, m, s = 0, k = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (j = 0; j < ac; j++)
	{
		for (m = 0; av[j][m]; m++)
		k++;
	}
	k += ac;

	str = malloc(sizeof(char) * k + 1);

	if (str == NULL)
	return (NULL);
	for (j = 0; j < ac; j++)
	{
		for (m = 0; av[j][m]; m++)
		{
			str[s] = av[j][m];
			s++;
		}
		if (str[sr] == '\0')
		{
			str[s++] = '\n';
		}
	}
	return (str);
}
