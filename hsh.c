#include "header.h"

/**
 * main - program that calls other functions
 *
 * Return: 0 upon success
 **/
int main(void)
{
	int index, status, execve_result, read;
	size_t buffer_size = 0;
	char *tokens_array[1024], *token, *path_found, *input_line = NULL;
	struct stat buffer;
	pid_t process_id;

	display_prompt(STDIN_FILENO, buffer);
	while ((read = getline(&input_line, &buffer_size, stdin)) != -1)
	{
		if (compare_strings(input_line, "\n") == 0)
		{
			display_prompt(STDIN_FILENO, buffer);
			continue;
		}
		token = strtok(input_line, "32\n\t\r");
		for (index = 0; token != NULL; index++)
		{
			tokens_array[index] = token;
			token = strtok(NULL, "32\n\t\r");
		}
		tokens_array[index] = NULL;
		identify_builtin(tokens_array[0]);
		path_found = find_executable_path(input_line);
		if (path_found == NULL)
			path_found = input_line;
		process_id = fork();
		if (process_id == -1)
			perror("fork");
		if (process_id == 0)
		{
			execve_result = execve(path_found, tokens_array, NULL);
			if (execve_result == -1)
				return (-1);
			free(input_line);
		}
		else
			wait(&status);
		display_prompt(STDIN_FILENO, buffer);
	}
	free(input_line);
	return (0);
}

