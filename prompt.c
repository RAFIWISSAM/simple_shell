#include "header.h"

/**
 * display_prompt - function that prints the prompt
 * @file_descriptor: file descriptor
 * @buffer: buffer
 * Return: none
 **/
void display_prompt(int file_descriptor, struct stat buffer)
{
	fstat(file_descriptor, &buffer);

	if (S_ISCHR(buffer.st_mode))
		print_prompt(PROMPT);
}

