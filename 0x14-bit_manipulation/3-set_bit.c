#include "main.h"

/**
 * set_bit - This function sets a bit at given index to 1
 * @n: This is the number the bit will be set in
 * @index: This is the index the bit will be set at
 * Return: 1 if it operates, or -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int greatest = 0x01;

	greatest <<= index;
	if (greatest == 0)
		return (-1);
	*n |= greatest;
	return (1);
}
