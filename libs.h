#ifndef SHELL_HELL
#define SHELL_HELL

#define BUFFSIZE 1024
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 98
#define _DELIM "\t\r\n\a\" "
#define SHNAME "./hsh"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

void sh_active(void);
void sh_passive(void);
void sh_file(char **argv);

char *read_line(void);
char *read_stream(void);
char **split_lines(char *line, char *delim);
char **split_lines_file(char *line);
char **clean_lines_comments(char *line);
int execute_args(char **args);
int make_child(char **args);
int make_child_as_is(char **args);

int sh_getline(char **lineptr, int *n, FILE *stream);
char *sh_getEnv(char *envVar);
int sh_isvalid(char *path, char **filename);

char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strncpy(char *dest, char *src, int n);
int _atoi(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, int old_size, int new_size);
char *sh_putenv(char *string);
void _setenv(char *var, char *value);
char *copy_info(char *name, char *value);

int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int builtin_setenv(char **var);
int builtin_unsetenv(char **var);
int builtin_help(char **args);

void sh_err(char *msg)

#endif
