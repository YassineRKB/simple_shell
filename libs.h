#ifndef _LIBS_HEAD_
#define _LIBS_HEAD_

#define BUFFSIZE 1024
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 98
#define _DELIM "\t\r\n\a\" "

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

void sh_active(void);
void sh_passive(void);
char *read_line(void);
char **split_lines(char *line, char *delim);
int execute_args(char **args);
int make_child(char **args);
char *sh_getPath(void);
int sh_isvalid(char *path, char **filename)

int builtin_exit(char **args);
#endif
