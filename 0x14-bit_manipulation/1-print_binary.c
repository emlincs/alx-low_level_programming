#include "main.h"

/**
 * print_binary - Prints a binary representation of a number
 * @n: The number to be printed
 *
 * Return: Nothing
 */
void print_binary(unsigned long int n)
{
	unsigned int tag = 0, max_value = 32768;

	if (n == 0)
	{
	_putchar('0');
	return;
	}

	while (max_value)
	{
	if (tag == 1 && (n & max_value) == 0)
	_putchar('0');
		else if ((n & max_value) != 0)
		{
		_putchar('1');
		tag = 1;
		}
	max_value >>= 1;
	}
}
