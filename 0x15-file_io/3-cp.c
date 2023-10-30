#include "main.h"

void close_file(int fd);
char *create_buff(char *file);

/**
 * create_buff - reserves 1024 bytes for a buffer
 * @file: The name of the file
 *
 * Return: A pointer to the new buffer
 */
char *create_buff(char *file)
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
 * close_file - Close file descriptor
 * @fb: file descriptor to be closed
 */
void close_file(int fb)
{
	int c;

	c = close(fb);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fb);
		exit(100);
	}
}

/**
 * main - Entry point
 * @agc: count of arguments
 * @agv: pointers to arguments
 *
 * Return: 0 on success, -1 on failure
 *
*/
int main(int agc, char *agv[])
{
	int fr, to, r, w;
	char *buff;

	if (agc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buff(agv[2]);
	fr = open(agv[1], O_RDONLY);
	r = read(fr, buff, 1024);
	to = open(agv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fr == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", agv[1]);
			free(buff);
			exit(98);
		}

		w = write(to, buff, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", agv[2]);
			free(buff);
			exit(99);
		}

		r = read(fr, buff, 1024);
		to = open(agv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	close_file(fr);
	close_file(to);

	return (0);
}
