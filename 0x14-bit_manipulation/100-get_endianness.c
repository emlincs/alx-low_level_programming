#include "main.h"

/**
 * get_endianness - This function examines endianness
 * Return: 0 if endian is big, 1 if endian is little
 */
int get_endianness(void)
{
	unsigned int k = 1;
	char *g = (char *)&k;

	if (*g)
		return (1);
	return (0);
}

