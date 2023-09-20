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

extern char **envarray;

char *extract_path(char **envp);
int evaluate_path(char **args, char **envp);
char *user_command(void);
void get_env(char **envp);
char **get_token(char *string);
void exit_shell(char **args, char *string, int _exit);
void *str_tok(char *str, const char *separator);
int fork_function(char **args, char **argv, char **envp,
char *string, int nproc, int cnt);

int str_cmp(char *s1, char *s2);
size_t str_cmp(char *s1, char *s2, size_t n);
int str_len(char *s);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);

int _putchar(char c);


#endif
