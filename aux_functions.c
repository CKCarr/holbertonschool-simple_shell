#include "shell.h"

/**
 *prompt - Printed character that prompts the user to enter a command.
 *Return: 0 if it receives a character
 */
int prompt(void)
{
	char *prompt = "($) ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	return (EXIT_SUCCESS);
}

/**
 *tokenizer - Functions that separates cmd & delimiters
 *@line: Command inserted by user
 *@delim: Delimiter
 *Return: The arguments that make up the commands
 */
char **tokenizer(char *line, char *delim)
{
	char *token = NULL, *copy_line = NULL;
	char **argv = NULL;
	int count_token = 0, i = 0;

	copy_line = malloc((sizeof(char) * _strlen(line)) + 1);
	if (copy_line == NULL)
	{	perror("malloc");
		return (NULL); }
	_strcpy(copy_line, line);
	token = strtok(line, delim);
	while (token != NULL)
		token = strtok(NULL, delim), count_token++;
	count_token++;

	argv = _calloc(count_token + 8, sizeof(char *));
	if (!argv)
	{	perror("calloc");
		free(copy_line);
		return (NULL); }
	token = strtok(copy_line, delim);
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!argv[i])
		{	perror("malloc");
			free_tokens(argv, i);
			free(copy_line);
			return (NULL); }
		_strcpy(argv[i], token), i++, token = strtok(NULL, delim);
	}
	if (!argv[0])
	{
		free_tokens(argv, i), free(copy_line);
		return (NULL);
	}
	free(copy_line), argv[i] = NULL;
	return (argv);
}

/**
 *find_path - Functions that finds the environment varibles in the path
 *@environ: Environment varibles in the path
 *Return: Environment variables
 */
char **find_path(char **environ)
{
	unsigned int i = 0;
	char *str_path = "PATH=";
	char *my_path = NULL;
	char **envp = NULL;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], str_path, 4) == 0)
		{
			my_path = malloc(sizeof(char) * _strlen(environ[i]) + 1);
			_strcpy(my_path, environ[i]);
			break;
		}
		i++;
	}

	envp = tokenizer(my_path, DELIM_PATH);
	free(my_path);

	return (envp);
}

/**
 * all_free - frees all the pointers
 * @argv: double pointer of commands
 * @envp: double pointer of path
 * @line: pointer to command
 * Return: void
 */
void all_free(char **argv, char **envp, char *line)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
		argv[i] = NULL;
	}
	free(argv);
	argv = NULL;

	for (i = 0; envp[i] != NULL; i++)
	{
		free(envp[i]);
		envp[i] = NULL;
	}
	free(envp);
	envp = NULL;

	free(line);
	line = NULL;
}

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of lements to the array
 * @size: size of the elements (char, int, float, etc)
 *
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *array  = NULL;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);

	array = malloc(nmemb * size);

	if (!array)
	{
		free(array);
		return (NULL);
	}

	for (i = 0; i < (nmemb * size); i++)
		array[i] = 0;

	return (array);
}
