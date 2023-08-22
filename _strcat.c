/**
 * custom_strcat - concatenate two strings
 * @destination: string 1
 * @source: string 2
 * Return: concatenated string \n.
 */
char *custom_strcat(char *destination, char *source)
{
	int dest_length = 0;
	int source_index = 0;

	while (destination[dest_length])
		dest_length++;

	while (source[source_index])
	{
		destination[dest_length] = source[source_index];
		dest_length++;
		source_index++;
	}
	destination[dest_length] = '\0';
	return (destination);
}

