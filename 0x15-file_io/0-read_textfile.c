#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile – This function reads text file then prints
 * to POSIX STDOUT
 * @filename: file to open
 * @letters:  No. of letters to be read and printed
 * Return: No. of letters read and printed. 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int src_fdesco, src_fdescr, src_fdescw;
	char *tmpbuff;

	if (filename == NULL)
		return (0);

	tmpbuff = malloc(sizeof(char) * letters);
	if (tmpbuff == NULL)
		return (0);

	src_fdesco = open(filename, O_RDONLY);
	if (src_fdesco < 0)
	{
		free(tmpbuff);
		return (0);
	}

	src_fdescr = read(src_fdesco, tmpbuff, letters);
	if (src_fdescr < 0)
	{
		free(tmpbuff);
		return (0);
	}

	src_fdescw = write(STDOUT_FILENO, tmpbuff, src_fdescr);
	free(tmpbuff);
	close(src_fdesco);

	if (src_fdescw < 0)
		return (0);
	return ((ssize_t)src_fdescw);
}

