#include "shell.h"

/**
 * get_command - Redirects to built funtions
 * @command: Command received
 * Return: Pointer to the funtions
 */
void (*get_command(char *command))(void)
{
	int indx = 0;

	builtins_t builtin_cmd[] = {
	{"env\n", env_print},
	{"help\n", print_shell_help},
	{NULL, NULL}
	};

	for (; builtin_cmd[indx].command != NULL; indx++)
	{
		if (_strcmp(builtin_cmd[indx].command, command) == 0)
			break;
	}
	return (builtin_cmd[indx].builtin_handler);
}

/**
 * env_print - Print all the enviroment
 * Return: void
 */
void env_print(void)
{
	char **env = environ;
	size_t len = 0;

	while (*env != NULL)
	{
		len = _strlen(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * print_shell_help - Print some options to execute
 * Return: void
 */
void print_shell_help(void)
{
	const char *help_text = "env:  Enviroment Variables\n"
				"ls:   Files and directories\n"
				"pwd:  Working directory\n"
				"exit: Exit shell\n";

	write(STDOUT_FILENO, help_text, _strlen(help_text));
}
/**
  * free_tokens - function that frees tokenized args
  * of user cli
  * @tokens: the args string parsed
  * Return: Always 0
  */
void free_tokens(char **tokens)
{
	int indx;

	if (tokens == NULL)
	{
		return;
	}
	while (tokens[indx] != NULL)
	{
		free(tokens[indx]);
		indx++;
	}
	free(tokens);
}
/**
 * _getenv - get env variables
 * @env_var: env variable
 * Return: env variable result, its content
 */
char *_getenv(char *env_var)
{
	int env_var_indx = 0;
	size_t len;
	char *value;

	if (!env_var)
	{
		perror("_getenv: invalid");
		return (NULL);
	}
	len = _strlen(env_var);
	while (environ[env_var_indx])
	{
		if (_strncmp(env_var, environ[env_var_indx], len) == 0)
		{
			if (environ[env_var_indx][len] == '=')
			{
				value = environ[env_var_indx] + len + 1;
				return (value);
			}
			env_var_indx++;
		}
	}
	perror("_getenv: environment variable not found");
	return (NULL);
}
