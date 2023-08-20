#include "header.h"

/**
 * check_permission - function that checks for user permission
 * @executable: files that need to be checked
 * Return: NULL
 **/
char *check_permission(char *executable)
{
	char *search_path, *token, *path_tokenized = NULL;
	char *path_copy = NULL;
	int i;
	struct stat file_stats;

	search_path = get_environment_variable("PATH");
	path_copy = duplicate_string(search_path);

	token = strtok(path_copy, ":");
	for (i = 0; token != NULL; i++)
	{
		path_tokenized = malloc(sizeof(char) * 1024);
		if (path_tokenized == NULL)
			return (NULL);
		set_memory(path_tokenized, 0, 1024);
		copy_string(path_tokenized, token);
		concatenate_string(path_tokenized, "/");
		concatenate_string(path_tokenized, executable);
		if (check_file_stat(path_tokenized, &file_stats) == 0)
		{
			return (path_tokenized);
		}
		token = strtok(NULL, ":");
		free(path_tokenized);
		path_tokenized = NULL;
	}
	return (NULL);
}

