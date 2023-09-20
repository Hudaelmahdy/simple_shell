#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;

char *extract_path(char **envarray);
int evaluate_path(char **argv, char **envarray);
char *user_command(void);
void get_env(char **envarray);
char **get_token(char *string);
void exit_shell(char **argv, char *string, int _exit);
char *_strtok(char *str, const char *separator);
int fork_function(char **argv, char **args, char **envarray,
char *string, int nproc, int cnt);

int str_cmp(char *s1, char *s2);
size_t strn_cmp(char *s1, char *s2, size_t n);
int str_len(char *s);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);

int _putchar(char c);


#endif
