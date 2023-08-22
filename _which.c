#include "header.h"

/**
 * _which - function that checks for user permission
 * @command: files that need to be checked
 * Return: NULL
 **/
char *_which(char *command)
{
	char *path, *tokens, *store_pathtoks = NULL;
	char *copy_path = NULL;
	int i;
	struct stat st;

	path = _getenv("PATH");
	copy_path = _strdup(path);

	tokens = strtok(copy_path, ":");
	for (i = 0; tokens != NULL; i++)
	{
		store_pathtoks = malloc(sizeof(char) * 1024);
		if (store_pathtoks == NULL)
			return (NULL);
		_memset(store_pathtoks, 0, 1024);
		_strcpy(store_pathtoks, tokens);
		_strcat(store_pathtoks, "/");
		_strcat(store_pathtoks, command);
		if (stat(store_pathtoks, &st) == 0)
		{
			return (store_pathtoks);
		}
		tokens = strtok(NULL, ":");
		free(store_pathtoks);
		store_pathtoks = NULL;
	}
	return (NULL);
}
