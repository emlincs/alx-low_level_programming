
#include "main.h"
#include <stdio.h>

/**
 * Oops_file - determines if files can be opened.
 * @file_gets: from file
 * @file_puts: to file
 * @argz: arguments scope
 * Return: no return.
 */
void Oops_file(int file_gets, int file_puts, char *argz[])
{
	if (file_gets == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argz[1]);
		exit(98);
	}
	if (file_puts == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argz[2]);
		exit(99);
	}
}

/**
 * main - check code 
 * @argx: number of arguments.
 * @argz: arguments scope
 * Return: Always 0.
 */
int main(int argx, char *argz[])
{
	int file_gets, file_puts, err_exit;
	ssize_t pchars, pwr;
	char tmpbuff[1024];

	if (argx != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_gets file_puts");
		exit(97);
	}

	file_gets = open(argz[1], O_RDONLY);
	file_puts = open(argz[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	Oops_file(file_gets, file_puts, argz);

	pchars = 1024;
	while (pchars == 1024)
	{
		pchars = read(file_gets, tmpbuff, 1024);
		if (pchars == -1)
			Oops_file(-1, 0, argz);
		pwr = write(file_puts, tmpbuff, pchars);
		if (pwr == -1)
			Oops_file(0, -1, argz);
	}

	err_exit = close(file_gets);
	if (err_exit == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_gets);
		exit(100);
	}

	err_exit = close(file_puts);
	if (err_exit == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_gets);
		exit(100);
	}
	return (0);
}


