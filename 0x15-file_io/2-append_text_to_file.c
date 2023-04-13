#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - A function that appends text to a file
 * @filename: The filename to open and append text in
 * @text_content: The NULL terminated string to add in the file
 * Return: 1 on success, -1 if the file can’t be created, or written on,
 * or if write fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descrpto, file_descrptw, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	file_descrpto = open(filename, O_RDWR | O_APPEND);
	if (file_descrpto < 0)
	{
		return (-1);
	}
		if (text_content == NULL)
		{
			close(file_descrpto);
			return (1);
		}
	while (*(text_content + len))
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

