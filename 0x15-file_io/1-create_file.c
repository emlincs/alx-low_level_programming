#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - A function that creates a file with content in it
 * @filename: Filename to create
 * @text_content: A NULL terminated string to write to the file
 * Return: 1 on success, -1 if file can’t be created, or written on,
 * or if write fails.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descrpto, file_descrptw, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	file_descrpto = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (file_descrpto < 0)
	{
		return (-1);
	}

	while (text_content && *(text_content + len))
	{
		++len;
	}

	file_descrptw = write(file_descrpto, text_content, len);
	close(file_descrpto);
	if (file_descrptw < 0)
	{
		return (-1);
	}
	return (1);
}

