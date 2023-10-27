#include "main.h"

/**
 * binary_to_uint - convert binary num to an unsigned int
 * @b: string of ones and zeros
 * Return: converted num or zero if there
 *	is other chars in the string than one and zero
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		n = n * 2 + (*b++ - '0');
	}

	return (n);
}
