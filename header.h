#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "$ "

extern char **environment;

/* HELPER FUNCTIONS */
int string_length(char *str);
char *string_concatenate(char *dest, char *src);
void print_string(char *str);
int print_character(char c);
char *string_duplicate(char *str);
int compare_strings(char *s1, char *s2);
char *string_copy(char *dest, char *src);
char *memory_set(char *s, char b, unsigned int n);
void print_prompt(char *str);

/* MAIN FUNCTIONS */
void display_prompt(int fd, struct stat buf);
void identify_builtin(char *command);
char *find_executable_path(char *command);
char *get_environment_variable(char *name);
char **duplicate_environment(char **original_environment);

/* BUILTIN FUNCTIONS */
typedef struct builtin_s
{
	char *identifier;
	int (*function)();
} builtin_t;
int exit_shell(void);
int display_environment(void);

#endif

