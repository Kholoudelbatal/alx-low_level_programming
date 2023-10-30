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
 * create_file - function that creates a file.
 *
 * @filename: name of the file to create
 *
 * @text_content: string to write to the file
 *
 * Return: 1 on success, -1 on failure
 * (file can not be created, file can not be written, write “fails”)
 * if filename is NULL return -1
 */
int create_file(const char *filename, char *text_content)
{
	int fb;
	ssize_t byte = 0, length = _strlen(text_content);

	if (!filename)
		return (-1);
	fb = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fb == -1)
		return (-1);
	if (length)
		byte = write(fb, text_content, length);
	close(fb);
	return (byte == length ? 1 : -1);
}
