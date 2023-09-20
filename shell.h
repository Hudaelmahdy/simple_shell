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
char *_strdub(char *str);
char *concat(char *name, char *sep, char *value);
char **tokenizeString(char *str, const char *separator);
void execute(char **args);
void *_reallocate(void *oldmem, unsigned int currSize, unsigned int reqSize);

extern char **env_array;

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


char *get_env(const char *name);
ls_path *push_node(ls_path **firstNode, char *str);
ls_path *pathlink(char *pathstr);
char *_which(char *fileName, ls_path *firstNode);

/**
 * struct builtin - function to the pointer with corresponding builtin command
 * @name: builtin name
 * @func: execute builtin command
*/
typedef struct builtin
{
	char *name;
	void (*func)(char **);
} builtin;

void(*lookup_builtin(char **argv))(char **argv);
int _atoi(char *string);
void exit_shell(char **argv);
void printenv(char **argv);
void set_env(char **argv);
void unset_env(char **argv);

void freeargv(char **argv);
void free_ls(ls_path *firstNode);


#endif
