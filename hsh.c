#include "shell.h"
/**
 * main - Function that implements commands line interface
 * Return: Exit_succsess or exit failure.
 */
int main(void)
{
	char *line = NULL, **argv = NULL, **envp = NULL;
	size_t line_size = 0;
	int status = 0;
	void (*function)(void) = NULL;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO) == 1)
			prompt();
		signal(SIGINT, handle);
		line_size = 0;
		line = read_line(line, line_size, status);
		if (_strcmp(line, "exit\n") == 0)
		{	free(line);
			return (WEXITSTATUS(status));
		}
		function = get_command(line);
		if (function != NULL)
		{	free(line), function();
			continue;
		}
		argv = tokenizer(line, DELIM_LINE);
		if (argv == NULL)
		{	free(line);
			continue;
		}
		envp = find_path(environ);
		argv[0] = _check_argv(argv[0], envp);
		if (!argv[0])
		{	all_free(argv, envp, line);
			status = FILE_NOT_FOUND;
			continue;
		}
		status = execute_child(argv, status);
		all_free(argv, envp, line);
	}
	return (WEXITSTATUS(status));
}
