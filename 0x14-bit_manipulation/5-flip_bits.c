#include "main.h"
/**
 * flip_bits - return number of bits you
 *	need to flip to get from one number to another
 * @m: seconed number
 * @n: first number
 * Return: number of bits needed to flip a num
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x = n ^ m;
	unsigned int i = 0;

	while (x)
	{
		if (x & 1ul)
			i++;
		x = x >> 1;
	}
	return (i);
}
