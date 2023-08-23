#include "main.h"

/**
 * bintest - Checks whether an executable path belongs to the /bin/ directory.
 *
 * @bin: The input executable path to be tested
 *
 * Return: 1 if the path is within /bin/, 0 otherwise
 */


int bintst(char *bin)
{
	char *tst = "/bin/";

	while (*tst != '\0')
	{
		if (*tst != *bin)
		{
			return (0);
		}
		tst = tst + 1;
		bin = bin + 1;
	}
	return (1);
}


/**
 * _path - Constructs a full path for an executable based on input conditions.
 *
 * @bin: The input executable name or path
 * @path: The environment PATH variable
 * @full: Pointer to store the constructed full path
 */

void _path(char *bin, char *path, char **full)
{
	int len2;

	if (bintest(bin))
	{
		len2 = 1 + strlen(bin);
		*full = (char *)malloc(sizeof(char) * len2);
		strcpy(*full, bin);
	}
	else
	{
		switch (bin[0])
		{
			case '.':
			case '/':
				len2 = 1 + strlen(bin);
				*full = (char *)malloc(sizeof(char) * len2);
				strcpy(*full, bin);
				break;

			default:
				len2 = strlen(path) + 2 + strlen(bin);
				*full = (char *)malloc(sizeof(char) * len2);

				strcpy(*full, path);
				strcat(*full, bin);

				break;
		}
	}
}
