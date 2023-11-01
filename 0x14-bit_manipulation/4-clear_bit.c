#include "main.h"

/**
 * clear_bit - This function sets a bit to 0 at given index
 * @n: This is the number the bit will set in
 * @index: This is the index where the bit will be set at
 * Return: 1 if it operates, or -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int greatest = 0x01;

	greatest = ~(greatest << index);
	if (greatest == 0x00)
		return (-1);
	*n &= greatest;
	return (1);
}

