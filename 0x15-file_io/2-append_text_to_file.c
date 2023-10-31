#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - This function appends text at the end of file
 * @filename: Name of a file to open and append 
 * @text_content: The added NULL terminated string 
 * Return: 1 on success, -1 if the file fails to be created, nor written.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int src_fdesco, src_fdescw, cont_len = 0;

	if (filename == NULL)
		return (-1);

	src_fdesco = open(filename, O_RDWR | O_APPEND);
	if (src_fdesco < 0)
		return (-1);
	if (text_content == NULL)
	{
		close(src_fdesco);
		return (1);
	}

	while (*(text_content + cont_len))
		cont_len++;

	src_fdescw = write(src_fdesco, text_content, cont_len);
	close(src_fdesco);
	if (src_fdescw < 0)
		return (-1);

	return (1);
}

