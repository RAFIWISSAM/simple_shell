#include "main.h"

/**
 * read_cmd -> reads the user input from stdin
 *
 * @line: input
 * @len: input
 *
 * Return: line
 */

ssize_t read_cmd(char **line, size_t *len)
{
        ssize_t readt = 0;

        if (isatty(STDIN_FILENO))
        {
                write(1, "($) ", 4);
        }
        readt = getline(line, len, stdin);
        if (readt == -1)
        {
                if (!isatty(STDIN_FILENO))
                {
                        return (-1);
                }
                free(line);
                exit(EXIT_FAILURE);
        }
        return (readt);
}

ssize_t read_cmd(char **line, size_t *len)
{
	ssize_t readt = 0;

	if (isatty(STDIN_FILENO))
	{
		write(1, "($) ", 4);
	}
	readt = getline(line, len, stdin);
	if (readt == -1)
	{
		if (!isatty(STDIN_FILENO))
		{
			return (-1);
		}
		free(line);
		exit(EXIT_FAILURE);
	}
	return (readt);
}
/**
 * tokenize - Splits a command line into individual arguments.
 *
 * @line: The input command line to be tokenized
 * @arg: An array to store the parsed arguments
 * Return: The number of arguments
 */

int tokenize(char *line, char **arg)
{
	int j;
	char *tock;

	for (tock = strtok(line, " \t\n\"\'\\#&*`"), j = 0; tock != NULL;
		 tock = strtok(NULL, " \t\n\"\'\\#&*`"), j++)
	{
		arg[j] = tock;
	}
	arg[j] = NULL;
	return (j);
}
