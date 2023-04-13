#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int safe_close(int);
/**
 * main – Entry point and Main function to copy file to
 * @argc: The number of command line and passed arguments
 * @argv: An array to the pointers of arguments
 * Return: 1 on success, exits on failure
 */
int main(int argc, char *argv[])
{
	char buffer[1024];
	int byte_result = 0, E_O_F = 1, fdsrc_file = -1, fddst_file = -1, error = 0;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fdsrc_file = open(argv[1], O_RDONLY);
	if (fdsrc_file < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fddst_file = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fddst_file < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		safe_close(fdsrc_file);
		exit(99);
	}
	while (E_O_F)
	{
	E_O_F = read(fdsrc_file, buffer, 1024);
		if (E_O_F < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			safe_close(fdsrc_file);
			safe_close(fddst_file);
			exit(98);
		}
		else if (E_O_F == 0)
		{
			break;
		}
	byte_result += E_O_F;
	error = write(fddst_file, buffer, E_O_F);
	if (error < 0)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		safe_close(fdsrc_file);
		safe_close(fddst_file);
		exit(99);
	}
	}
		error = safe_close(fddst_file);
		if (error < 0)
		{
			safe_close(fdsrc_file);
			exit(100);
		}
		error = safe_close(fdsrc_file);
		if (error < 0)
		{
			exit(100);
		}
	return (0);
}
/**
 * safe_close - A function that closes file
 * and prints error when the file is closed
 * @description: Description error when file is closed
 * Return: 1 on success, -1 on failure
 */
int safe_close(int description)
{
	int error;
	error = close(description);
	if (error < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd file %d\n", description);
	}
	return (error);
}
