/**
 * custom_strcat - concatenate two strings
 * @destination: string 1
 * @source: string 2
 * Return: concatenated string \n.
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int j = 0;

	while (dest[dest_len])
		dest_len++;

	while (src[j])
	{
		dest[dest_len] = src[j];
		dest_len++;
		j++;
	}
	dest[dest_len] = '\0';
	return (dest);
}

