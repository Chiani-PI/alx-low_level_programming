#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Function reads any text file & prints it to the POSIX STDOUT
 * @filename: The text file that will be read
 * @letters: The total number of letters that will be read
 * Return: The actual number of letters the function read and printed,
 * otherwise 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fdo;
	ssize_t wr;
	ssize_t tre;

	fdo = open(filename, O_RDONLY);
	if (fdo == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	tre = read(fdo, buff, letters);
	wr = write(STDOUT_FILENO, buff, tre);

	free(buff);
	close(fdo);
	return (wr);
}
