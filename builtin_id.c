#include "header.h"

/**
 * identify_builtin - function that identifies a builtin function
 * @input_command: commands that pass through the function
 * Return: builtin function
 **/
void identify_builtin(char *input_command)
{
	int i;

	builtin_t builtin_commands[] = {
		{"exit", perform_exit},
		{"env", display_environment},
		{NULL, NULL}
	};

	for (i = 0; builtin_commands[i].function != NULL; i++)
	{
		if (compare_strings(builtin_commands[i].id, input_command) == 0)
		{
			builtin_commands[i].function();
		}
		if (builtin_commands[i].function == NULL)
		{
			print_error("Return NULL");
			exit(EXIT_SUCCESS);
		}
	}
}

/**
 * perform_exit - builtin function that exits the shell
 *
 * Return: exit
 **/
int perform_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * display_environment - function that prints the environment
 *
 * Return: 0
 **/
int display_environment(void)
{
	unsigned int i;

	for (i = 0; environ[i] != '\0'; i++)
		print_string(environ[i]);
	return (0);
}

