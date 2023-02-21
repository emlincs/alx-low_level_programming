#include <unistd.h>
#include "main.h"

/**
 * main - Check description
 * Description: It prints _putchar, followed by a new line.
 * Return: 0.
 */
int main(void)
{
	char word[9] = "alx_se_c";
	int i;

	for (i = 0; i < 9; i++)
		_putchar(word[i]);
	_putchar('\n');

	return (0);
}
