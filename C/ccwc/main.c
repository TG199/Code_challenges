#include "main.h"
#include <stdio.h>

/**
 * main - Entry point of program
 * @argc: argument count
 * @argv: argument vectors
 *
 * Return: Always (0) on sucess
 */

int main(int argc, char **argv)
{
	ssize_t line, word, chars, bytes;
	ssize_t total_lines = 0, total_words = 0, total_chars = 0, total_bytes = 0;
	char *opt;
	size_t bufsize;
	char *file, *buffer = NULL;
	int i;


	if (argc < 1)
	{
		fprintf(stderr, "Usage: %s [-options] [file] ...\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (argc == 1)
	{
		
		while (fgets(buffer, bufsize, stdin) != NULL)
		{
			if (bufsize)
				bufsize *= 2;
		}

	}

	for (i = 1; i  < argc; i++)
	{
		opt = argv[i];
		
		if (opt[0] == '-')
		{
			if (i + 1 < argc)
			{
				file = argv[i + 1];
				if (strcmp(opt, "-l") == 0)
				{
					
					line = line_count(file);
					printf("%ld %s\n", line, file);
					total_lines += line;
				}
				else if (strcmp(opt, "-w") == 0)
				{
					word = word_count(file);
					printf("%ld %s\n", word, file);
					total_words += word;
				}
				else if (strcmp(opt, "-m") == 0)
				{
					chars = chars_count(file);
					printf("%ld %s\n", chars, file);
					total_bytes += chars;
				}
				else if (strcmp(opt, "-c") == 0)
				{
					bytes = bytes_count(file);
					printf("%ld %s\n", bytes, file);
					total_bytes += bytes;
				}
				else
				{
					fprintf(stderr, "Wrong option specified\n");
				}
				i++;
			}
			else
			{
				fprintf(stderr, "Missing argument for option %s\n", opt);
				return (EXIT_FAILURE);
			}
		}
		else
		{
			file = opt;
			line = line_count(file);
			word = word_count(file);
			bytes = bytes_count(file);
			printf("  %ld  %ld %ld %s\n", line, word, bytes, file);
			total_lines += line;
			total_words += word;
			total_chars += chars;
			total_bytes += chars;
		}
	}

	return (0);
}
