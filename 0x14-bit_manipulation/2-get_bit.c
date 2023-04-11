#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index
 * @n: The number to source bit from
 * @index: The index of the bit to source
 * Return: The value of the bit at the given index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int abs_val = 0x01;

	abs_val <<= index;
	if (abs_val == 0)
		return (-1);
	if ((n & abs_val))
	{
		return (1);
	}
	else
		return (0);
}
