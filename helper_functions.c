#include "header.h"

/**
 * calculate_string_length - function that counts the length of a string
 * @str: string that passes through the function
 * Return: length
 **/
int calculate_string_length(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * concatenate_strings - function that concatenates two strings
 * @destination: string to which the source will be concatenated
 * @source: string to be concatenated
 * Return: pointer
 **/
char *concatenate_strings(char *destination, char *source)
{
	int index;
	int dest_length = calculate_string_length(destination);

	for (index = 0; source[index] != '\0'; index++)
	{
		destination[dest_length + index] = source[index];
	}
	destination[dest_length + index] = '\0';
	return (destination);
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
 * duplicate_string - function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a parameter
 * @str: pointer to string
 * Return: pointer
 **/
char *duplicate_string(char *str)
{
	int index;
	char *array;

	if (str == NULL)
	{
		return (NULL);
	}
	array = malloc(sizeof(char) * (calculate_string_length(str) + 1));
	if (array == NULL)
	{
		return (NULL);
	}
	for (index = 0; index < calculate_string_length(str); index++)
	{
		array[index] = str[index];
	}
	array[index] = '\0';
	return (array);
}

