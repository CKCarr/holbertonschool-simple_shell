#include "shell.h"

/**
 * _check_argv - check of argv
 * @command: Command recived
 * @envp: PATH
 * Return: concat, NULL
 */
char *_check_argv(char *command, char **envp)
{
	char *concat = NULL;
	struct stat st;
	int i = 0, len_command = 0, len_envp = 0;

	if (stat(command, &st) == 0)
		return (command);

	for (i = 1; envp && envp[i]; i++)
	{
		len_command = _strlen(command);
		len_envp = _strlen(envp[i]);

		concat = malloc(sizeof(char) * (len_command + len_envp) + 2);

		if (concat == NULL)
			return (NULL);

		_strcpy(concat, envp[i]);
		_strcat(concat, "/");
		_strcat(concat, command);

		if (stat(concat, &st) == 0)
		{
			free(command);
			return (concat);
		}
		free(concat);
	}
	print_error(command);
	free(command);
	return (NULL);
}

/**
 * execute_child - creates a child and executes it
 * @argv: list of arguments to execute
 * @status: status of father
 * Return: status.
 */
int execute_child(char **argv, int status)
{
	pid_t child_pid = 0;

	child_pid = fork();
	if (child_pid == -1)
		return (WEXITSTATUS(status));
	if (child_pid == 0)
		execve(argv[0], argv, environ);
	else
		wait(&status);

	return (status);
}

/**
 * read_line - reads the input line
 * @line: buffer to store line
 * @line_size: number of bytes of line
 * @status: status of father
 * Return: pointer to buffer line
 */
char *read_line(char *line, size_t line_size, int status)
{
	ssize_t command = 0;

	command = getline(&line, &line_size, stdin);
	if (command == EOF)
	{
		free(line);
		exit(WEXITSTATUS(status));
	}

	return (line);
}

/**
 * print_error - Print erro if not found file
 * @command: Receved command
 * Return: void
 */
void print_error(char *command)
{
	int size_concat = 0, all_size = 0;
	char *concat = NULL;
	char *str1 = "./hsh: 1: ";
	char *str2 = ": not found\n";

	all_size = _strlen(str1) + _strlen(str2) + _strlen(command) + 1;
	concat = malloc(sizeof(char) * all_size);
	if (concat == NULL)
		exit(2);

	_strcpy(concat, str1);
	_strcat(concat, command);
	_strcat(concat, str2);
	size_concat = _strlen(concat);

	write(2, concat, size_concat);
	free(concat);
}

/**
 * handle - handles signal
 * @num: unused parameter
 * Return: void
 */
void handle(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n($) ", 5);
}
