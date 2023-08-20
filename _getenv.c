#include "header.h"

/**
 * _getenv - function that gets the environment
 * @key: string pointer
 * Return: value
 **/
char *_getenv(char *key)
{
	int cmp_result, i;
	char *value, **env_copy;

	env_copy = duplicate_env(environ);

	for (i = 0; env_copy[i] != '\0'; i++)
	{
		value = strtok(env_copy[i], "=");
		cmp_result = compare_strings(key, value);
		if (cmp_result == 0)
		{
			value = strtok(NULL, "\0");
			return (value);
		}
	}
	return (NULL);
}

/**
 * duplicate_env - function that duplicates the environment
 * @original_env: environment to be duplicated
 * Return: duplicated environment as a double pointer
 **/
char **duplicate_env(char **original_env)
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
		env_copy[i] = malloc(sizeof(char) * length_of_string(original_env[i]) + 1);
		if (env_copy[i] == NULL)
			return (NULL);
		copy_string(env_copy[i], environ[i]);
	}
	return (env_copy);
}

