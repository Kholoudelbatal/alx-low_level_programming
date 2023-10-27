#include "main.h"
/**
 * get_endianness - checks endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned long int e = 1;

	return (*(char *)&e);
}
