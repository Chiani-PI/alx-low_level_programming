#include "main.h"

/**
 * create_file - Function to create a file
 * @filename: The pointer to the name of the file to be created
 * @text_content: The pointer to the string to be written to the file
 *
 * Return: 1 (Success), else -1
 */
int create_file(const char *filename, char *text_content)
{
	int fdo, wr, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fdo = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(fdo, text_content, len);

	if (fdo == -1 || wr == -1)
		return (-1);

	close(fdo);

	return (1);
}
