#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv, char **env);
void prompt(void);
void handle(int sig);
void _EOF(char *buffer);
void exit(char **command);
void child(char **command, char *name, char **env, int cycles);
void ch_dir(const char *path);
void execute(char **command, char *name, char **env, int cycles);
void print_env(char **env);
char **_getpath(char **env);
void error(char *name, char **command, int cycles);
char **tokening(char *buffer, const char *str);
void free_double_pointer(char **command);
void free_exit(char **command);
int strcmp(char *str1, char *str2);
unsigned int strlen(char *str);
char *strcpy(char *dest, char *src);
char *strcat(char *dest, char src);
int _atoi(char *str);

#endif
