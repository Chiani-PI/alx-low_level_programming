#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fdo);

/**
 * create_buffer - Function will allocate 1024 bytes to a buffer
 * @file: The file name for which the buffer is will store chars
 *
 * Return: The pointer to the freshly allocated buffer
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - Function to close the file descriptors
 * @fdo: The file descriptor which is to be closed
 */
void close_file(int fdo)
{
	int cd;

	cd = close(fdo);

	if (cd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdo);
		exit(100);
	}
}

/**
 * main - Function to copy a file's contents to another file
 * @argc: The tnumber of arguments passed into the program
 * @argv: The array of pointers which point to the arguments
 *
 * Return: 0 if successful
 *
 * Description: If argument count is not correct, Exit with code 97
 * and print Usage: cp file_from file_to, followed by a new line,
 * on the POSIX std err..
 * if file_to is already in existence, truncate it..
 * If file_from doesn't exist or can't be read, Exit with code 98 and
 * print Error 'Can't read from file NAME_OF_THE_FILE', followed by a new line,
 * on the POSIX std err..
 * If file_to cannot be created or written to, Exit with code 99 and
 * print Error 'Can't write to NAME_OF_THE_FILE', followed by a new line,
 * on the POSIX std err
 * where NAME_OF_THE_FILE is the 2nd argument passed to the program..
 * If file_to or file_from cannot be closed, Exit with code 100 and
 * print Error 'Can't close fd FD_VALUE', followed by a new line,
 * on the POSIX std err
 * where FD_VALUE is the value of the file descriptor..
 */
int main(int argc, char *argv[])
{
	int from, to, re, wr;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	re = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || re == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		wr = write(to, buff, re);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		re = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (re > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}
