#include "main.h"

/**
 * append_text_to_file - Function to append text at the end of a file
 * @filename: The pointer to the file name
 * @text_content: The string to be added to the end of the file
 *
 * Return: 1 if success, else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int op, wr, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	wr = write(op, text_content, len);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);

	return (1);
}
