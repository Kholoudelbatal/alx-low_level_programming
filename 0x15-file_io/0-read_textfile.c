#include "main.h"
/**
 * read_textfile - reads a text file and prints it
 * to the POSIX standard output.
 * @filename: name of the file
 * @letters: letters to be read
 *
 * Return: actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fb;
	ssize_t byte;
	char buf[READ_BUF_SIZE * 8];

	if (!filename || !letters)
		return (0);
	fb = open(filename, O_RDONLY);
	if (fb == -1)
		return (0);
	byte = read(fb, &buf[0], letters);
	byte = write(STDOUT_FILENO, &buf[0], byte);
	close(fb);
	return (byte);
}
