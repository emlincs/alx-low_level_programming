#include "main.h"

/**
 * set_bit - A function that sets a bit at given index to 1
 * @n: A pointer to the number the bit will be set in
 * @index: The index where bit will be set
 * Return: 1 if it executed, or -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int abs_val = 0x01;

	abs_val = abs_val << index;
	if (abs_val == 0)
		return (-1);
	*n = (*n | abs_val);
	return (1);
}
