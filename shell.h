#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *string);
char *_strdup(char *str);
char *concat(char *name, char *sep, char *value);
char **tokenizeString(char *str, const char *separator);
void execute(char **args, char **envarray);
void *re_alloc(void *oldmem, unsigned int currsize, unsigned int reqsize);


extern char **envarray;

/**
 * struct ls_path - link the list that containing path of directories
 * @directory: the directory in the path
 * @next_dir: pointer to the next directory
*/

typedef struct ls_path
{
	char *directory;
	struct ls_path *next_dir;
} ls_path;


char *get_env(const char *name, char **envarray);
ls_path *push_node(ls_path **firstNode, char *str);
ls_path *pathlink(char *pathstr);
char *locate_command(char *command_name, ls_path *firstNode);

/**
 * struct builtin - function to the pointer with corresponding builtin command
 * @name: builtin name
 * @func: execute builtin command
*/
typedef struct builtin
{
	char *name;
	void (*func)(char **, char **);
} builtin;


void (*lookup_builtin(char **argv, char **envarray))(char **, char **);
int _atoi(char *string);
void exit_shell(char **argv, char **envarray);
void print_env(char **argv, char **envarray);
void set_env(char **argv, char **envarray);
void unset_env(char **argv, char **envarray);

void freeargv(char **argv);
void free_ls(ls_path *firstNode);


#endif
