#ifndef SHELL_H
#define SHELL_H

/* Librarys */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#include <errno.h>
#include <signal.h>
#include <stddef.h>

/* Global variables */

extern char **environ;

/* Structures */

/**
 * struct builtins_s - builtin structure
 * @command: Received command
 * @builtin_handler: Pointer to function
 */
typedef struct builtins_s
{
	char *command;
	void (*builtin_handler)(void);
} builtins_t;

/* Prototypes */

char **tokenizer(char *line, char *delim);

char **find_path(char **environ);

char *get_executable_path(char *command, char **envp);

char *read_line(char *line, size_t line_size, int status);

int execute_child(char **argv, int status);

void print_error(char *command);

void handle(int num);

/* string prototypes */
int _strlen(const char *string);

int _strncmp(char *s1, char *s2, size_t n);

int _strcmp(char *s1, char *s2);

char *_strcpy(char *dest, char *src);

char *_strcat(char *dest, char *src);

/* aux functions prototypes */
int prompt(void);

void all_free(char **argv, char **envp, char *line);

void *_calloc(unsigned int nmemb, unsigned int size);


/* built in functions prototypes */
void (*get_command(char *command))(void);

void print_shell_help(void);

void env_print(void);

void free_tokens(char **tokens);
/* Macros */

#define TRUE 1
#define DELIM_PATH ":="
#define DELIM_LINE " \t\n"
#define EXIT "exit"
#define FILE_NOT_FOUND 32512

#endif /* SHELL_H */
