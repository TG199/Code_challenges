#include "main.h"


/**
 * line_count - count number of linees in a file
 * @input: input to count lines
 *
 * Return: Number of lines counted
 */
ssize_t line_count(const char *input)
{

	ssize_t bufsize = 100;
	ssize_t bytes_read, line_count;
	char *buffer;
	int fd;
	char c;

	if (input == NULL)
	{
		perror("ERROR: empty file");
		return (-1);
	}
	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		perror("Memory allocation error");
		return (-1);
	}

	fd = open(input, O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}


	bytes_read = 0;
	line_count = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (bytes_read >= bufsize)
		{
			bufsize *= 2;
			buffer = realloc(buffer, bufsize);
		
			if (buffer == NULL)
			{
				perror("Memory reallocation error");
				free(buffer);
				close(fd);
				return (-1);
			}
		}
		if (c == '\n')
		{
			line_count++;
		}
		buffer[bytes_read] = c;
		bytes_read++;
	}
	free(buffer);
	close(fd);
	return (line_count);
}
