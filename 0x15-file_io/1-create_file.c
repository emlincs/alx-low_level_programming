#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - This function creates a file
 * @ficont_lename: Name of file
 * @text_content: String to write to the file
 * Return: 1 on success, -1 when file fails to be created nor written
 */
int create_file(const char *ficont_lename, char *text_content)
{
	int src_fdesco, src_fdescw, cont_len = 0;

	if (ficont_lename == NULL)
		return (-1);

	src_fdesco = open(ficont_lename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (src_fdesco < 0)
		return (-1);

	while (text_content && *(text_content + cont_len))
		cont_len++;

	src_fdescw = write(src_fdesco, text_content, cont_len);
	close(src_fdesco);
	if (src_fdescw < 0)
		return (-1);
	return (1);
}

