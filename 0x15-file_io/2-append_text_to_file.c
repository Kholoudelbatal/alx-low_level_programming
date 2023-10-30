#include "main.h"

/**
 * _strlen - return the len of string
 * @str: string to be measured
 * Return: int num f the string len
 */
int _strlen(char *str)
{
	int ind = 0;

	if (!str)
		return (0);

	while (*str++)
		ind++;
	return (ind);
}



/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of the file
 * @text_content: string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fb;
	ssize_t byte = 0, length = _strlen(text_content);

	if (!filename)
		return (-1);
	fb = open(filename, O_WRONLY | O_APPEND);
	if (fb == -1)
		return (-1);
	if (length)
		byte = write(fb, text_content, length);
	close(fb);
	return (byte == length ? 1 : -1);
}
