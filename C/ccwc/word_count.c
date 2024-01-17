#include "main.h"
int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}
/**
 * word_count - count words in a file
 * @file: File to count words
 *
 * Return: Number of words counted
 */
ssize_t word_count(char *file)
{
	ssize_t bufsize = 100, bytes_read, space_count;
	char *buffer;
	int fd, in_word;
	char c;

	if (file == NULL)
	{
		perror("ERROR: empty file");
		return (-1);
	}
	buffer = malloc(sizeof(char) * bufsize);

	if (buffer == NULL)
	{
		perror("Memory Allocation Error");
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		free(buffer);
		return (-1);
	}

	bytes_read = 0;
	space_count = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (bytes_read >= bufsize)
		{
			bufsize *= 2;
			buffer = realloc(buffer, bufsize);

			if (buffer == NULL)
			{
				perror("Error Reallocating buffer");
				free(buffer);
				close(fd);
				return (-1);
			}
		}/*
		if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v')
		{
			space_count++;
		}*/
		
		if (_isspace(c))
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			space_count++;
		}
		buffer[bytes_read] = c;
		bytes_read++;
	}
	free(buffer);
	close(fd);
	return (space_count);
}
