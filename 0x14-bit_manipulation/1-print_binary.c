#include "main.h"

/**
 * print_binary - print binary rep of num
 * @n: the number to be processed
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int started = 0;

	while (mask > 0)
	{
		if ((n & mask) || started)
		{
			_putchar((n & mask) ? '1' : '0');
			started = 1;
		}
		mask >>= 1;
	}

	if (!started)
		_putchar('0');
}
