#include "main.h"
/**
 * set_bit -  set value of a bit to 1 at given index
 * @index: the bit to set
 * @n: num to ind
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	return (!!(*n |= 1L << index));
}
