#include "main.h"
/**
* print_binary - This function prints binary number without % or /
* @n: The number that will be printed
* Return: None
*/
void print_binary(unsigned long int n)
{
unsigned int start = 0, end = 32768;
	if (n == 0)
	{
	_putchar('0');
	return;
	}

	while (end)
	{
		if (start == 1 && (n & end) == 0)
		_putchar('0');
		else if ((n & end) != 0)
	{
		_putchar('1');
			start = 1;
	}
	end >>= 1;
	}
}
