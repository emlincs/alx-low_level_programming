#include "main.h"

/**
 * binary_to_uint – this function changes a binary number to an unsigned int.
 * @b: this is a string pointer that holds a binary number
 *
 * Return: unsigned int that has a value of binary number, or 0 if it is an error
 */
unsigned int binary_to_uint(const char *b)
{
	int z;
	unsigned int entryNum;

	entryNum = 0;
	if (!b)
		return (0);
	for (z = 0; b[z] != '\0'; z++)
	{
		if (b[z] != '0' && b[z] != '1')
			return (0);
	}
	for (z = 0; b[z] != '\0'; z++)
	{
		entryNum <<= 1;
		if (b[z] == '1')
			entryNum += 1;
	}
	return (entryNum);
}

