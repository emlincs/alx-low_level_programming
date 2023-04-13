#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>

/**
 * read_textfile - A function that reads a text file and then prints
 * on to the POSIX STDOUT
 * @filename: The filename to be opened
 * @letters: The number of letters to be read and printed
 * Return: The number of letters read and printed, or return 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descrpto, file_descrptr, file_descrptw;
	char *buffer;


	if (filename == NULL)
		return (0);


	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);


	file_descrpto = open(filename, O_RDONLY);
	if (file_descrpto < 0)
	{
		free(buffer);
		return (0);
	}


	file_descrptr = read(file_descrpto, buffer, letters);
	if (file_descrptr < 0)
	{
		free(buffer);
		return (0);
	}


	file_descrptw = write(STDOUT_FILENO, buffer, file_descrptr);
	free(buffer);
	close(file_descrpto);


	if (file_descrptw < 0)
		return (0);
	return ((ssize_t) file_descrptw);
}

