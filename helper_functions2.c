#include "header.h"

/**
 * string_length - function that counts the length of a string
 * @str: string that passes through the function
 * Return: length
 **/
int string_length(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * string_concatenate - function that concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer
 **/
char *string_concatenate(char *dest, char *src)
{
	int index;
	int dest_len = string_length(dest);

	for (index = 0; src[index] != '\0'; index++)
	{
		dest[dest_len + index] = src[index];
	}
	dest[dest_len + index] = '\0';
	return (dest);
}

/**
 * print_string - function that prints a string
 * @str: pointer to the string
 * Return: none
 **/
void print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		print_character(str[i]);
		i++;
	}
	print_character('\n');
}

/**
 * print_character - writes the character to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_character(char c)
{
	return (write(1, &c, 1));
}

/**
 * string_duplicate - function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a parameter
 * @str: pointer to string
 * Return: pointer
 **/
char *string_duplicate(char *str)
{
	int index;
	char *new_str;

	if (str == NULL)
	{
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (string_length(str) + 1));
	if (new_str == NULL)
	{
		return (NULL);
	}
	for (index = 0; index < string_length(str); index++)
	{
		new_str[index] = str[index];
	}
	new_str[index] = '\0';
	return (new_str);
}

