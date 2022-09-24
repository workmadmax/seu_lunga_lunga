#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 999
#endif

/**
 * @brief Reads a line from a file descriptor
 * 
 * @param fd file descriptor to read.
 * @return Return a string including \\n if is a line.
 * In case of the file dont have \\n return
 * a string without \\n, NULL if the file is
 * empty or error occurred.
 */
char        *get_next_line(int fd);

char        *get_read(int fd, char *str);
char        *get_string(char *str);
size_t      gnl_strlen(char *str);
char        *gnl_strchr(char *str, int c);
char        *gnl_strjoin(char *s1, char *s2);
char        *gnl_dup(char *s);

# endif