#include "main.h"

/**
 * bytes_count - count the number of bytes in a textfile
 * @letter: text file to count bytes
 *
 * Return: no of character count
 */

ssize_t bytes_count(char *file)
{
	int fd;
	ssize_t bufsize = 100;
	ssize_t bytes_read;
	char *buffer = malloc(sizeof(char) * bufsize);
	char c;

	if (file == NULL)
	{
		perror("Error:empty file");
		free(buffer);
		return (-1);
	}

	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		perror("Failed to open file");
		free(buffer);
		return (-1);
	}

	bytes_read = 0;
	while (read(fd, &c, 1)  == 1)
	{
		if (bytes_read >= bufsize )
		{
			bufsize *= 2;
			buffer = realloc(buffer, bufsize);

			if (buffer == NULL)
			{
				perror("Memory Allocation Error");
				free(buffer);
				close(fd);
				return (-1);
			}
		}
		buffer[bytes_read] = c;
		bytes_read++;	
	}

	free(buffer);
	close(fd);
	return (bytes_read);
}
