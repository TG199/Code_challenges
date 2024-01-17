#ifndef MAIN_H
#define MAIN_H

/*header files*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


ssize_t bytes_count(char *file);
ssize_t word_count(char *file);
ssize_t line_count(char *file);


#endif /* MAIN_H */
