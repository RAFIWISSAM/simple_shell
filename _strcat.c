/**
<<<<<<< HEAD
 * custom_strcat - Concatenate two strings
 * @dest: The destination string
 * @src: The source string to append
 * Return: Pointer to the concatenated string
=======
 * custom_strcat - concatenate two strings
 * @destination: string 1
 * @source: string 2
 * Return: concatenated string \n.
>>>>>>> b4ef5636ff801a4e0e37a5f9ae8447e7b8127369
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
<<<<<<< HEAD
	int i = 0;
=======
	int j = 0;
>>>>>>> b4ef5636ff801a4e0e37a5f9ae8447e7b8127369

	while (dest[dest_len])
		dest_len++;

<<<<<<< HEAD
	while (src[i])
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
=======
	while (src[j])
	{
		dest[dest_len] = src[j];
		dest_len++;
		j++;
>>>>>>> b4ef5636ff801a4e0e37a5f9ae8447e7b8127369
	}
	dest[dest_len] = '\0';
	return (dest);
}
<<<<<<< HEAD
=======

>>>>>>> b4ef5636ff801a4e0e37a5f9ae8447e7b8127369
