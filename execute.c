#include "main.h"

/**
 * execute - Forks a child process and runs the specified command.
 *
 * @arg: Array of arguments for the command
 * @full: Full path to the executable command
 * @line: The input command line
 * Return: Exit status of the forked process
 */

int execute(char **arg, char *full, char *line)
{
	int pd = fork();
	int status = 0;
	int fork_status = 0;

	if (pd == 0)
	{
		if (execve(full, arg, NULL) == -1)
		{
			free(full);
			free(line);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(full);
		if (WIFEXITED(status))
			fork_status = WEXITSTATUS(status);
	}
	return (fork_status);
}
