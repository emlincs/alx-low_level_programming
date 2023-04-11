#include "main.h"

/**
 * clear_bit - A function that sets a bit to 0 at a given index
 * @n: A pointer to the number the bit will be set in
 * @index: The index where bit will be set
 * Return: 1 if it executed, or -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int abs_val = 0x01;

	abs_val <<= index;
	if (abs_val == 0)
		return (-1);
	abs_val = ~abs_val;
	*n &= abs_val;
	return (1);
}
