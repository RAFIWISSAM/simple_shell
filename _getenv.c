#include "header.h"

/**
 * _getenv - function that gets the environment
 * @name: string pointer
 * Return: token
 **/
char *_getenv(char *name)
{
	int compare, i;
	char *token, **env_copy;

	env_copy = copy_env(environ);

	for (i = 0; env_copy[i] != '\0'; i++)
	{
		token = strtok(env_copy[i], "=");
		compare = _strcmp(name, token);
		if (compare == 0)
		{
			token = strtok(NULL, "\0");
			return (token);
		}
	}
	return (NULL);
}

/**
 * copy_env - function that copies the environment
 * @original_env: environment that passes through function
 * Return: double ptr copy_env
 **/
char **copy_env(char **original_env)
{
	char **env_copy;
	int env_len, i;

	for (env_len = 0; original_env[env_len] != NULL; env_len++)
		;
	env_copy = malloc(sizeof(char **) * env_len);
	if (env_copy == NULL)
		return (NULL);
	for (i = 0; original_env[i] != NULL; i++)
	{
		env_copy[i] = malloc(sizeof(char) * _strlen(original_env[i]) + 1);
		if (env_copy[i] == NULL)
			return (NULL);
		_strcpy(env_copy[i], environ[i]);
	}
	return (env_copy);

}
