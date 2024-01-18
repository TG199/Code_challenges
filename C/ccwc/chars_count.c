#include "main.h"

/**
 * chars_count - count number of character in a file
 * file: file to count from
 *
 * Return: number of chars counted
 */
ssize_t chars_count(char *file)
{
	ssize_t bufsize = 1000;
	ssize_t bytes_read, char_count;
	char *buffer;
	int fd;
	char c;

	if (file == NULL)
	{
		perror("Error: empty file");
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		perror("Error: Memory allocation failure");
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: can't open file");
		free(buffer);
		return (-1);
	}

	bytes_read = 0;
	char_count = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (bytes_read == bufsize)
		{
			bufsize *= 2;
			buffer = realloc(buffer, bufsize);
			if (buffer == NULL)
			{
				perror("Error: Reallocation failure");
				free(buffer);
				close(fd);
				return(-1);
			}
		}
		if ((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z'))
		{
			char_count++;
		}
		buffer[bytes_read] = c;
		bytes_read++;
	}
	free(buffer);
	close(fd);
	return(char_count);
}




