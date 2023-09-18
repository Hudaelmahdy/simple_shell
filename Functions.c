#include "shell.h"

/**
*free_double_pointer - function to free a dynamically allocated memory
*@command: pointer to memory
*Return: nothing
*/

void free_double_pointer(char **command)
{
	size_t i = 0;

if (command == NULL)
return;

while (command[i])
{
	free(command[i]);
	i++;
}

if (command[i] == NULL)
free(command[i]);
free(command);
}


/**
*free_exit - function to frees memory and exit
*@command: pointer to memory
*Return: nothing
*/

void free_exit(char **command)
{
	size_t i = 0;

if (command == NULL)
return;

while (command[i])
{
	free(command[i]);
	i++;
}
if (command[i] == NULL)
free(command[i]);
free(command);
exit(EXIT_FAILURE);
}


/**
*child - function to create child process
*@command: poiter
*@name: pointer to name of shell
*@env: pointer to enviromental variables
*@cycles: excuted cycles
*Return: nothing
*/

void child(char **command, char *name, char **env, int cycles)
{
	int pid = 0;
	int status = 0;
	int child_status = 0;

pid = fork();
if (pid < 0)
{
	perror("Error: ");
	free_exit(command);
}
else if (pid == 0)
{
	execute(command, name, env, cycles);
	free_double_pointer(command);
}
else
	{
	child_status = waitpid(pid, &status, 0);
	if (child_status < 0)
	{
		free_exit(command);
	}
	free_double_pointer(command);
	}
}

/**
*ch_dir - function to change working directory
*@path: new dir
*Return: 0 on sucess, -1 on failure
*/

int ch_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

if (path == NULL)
path = getcwd(buf, size);
if (chdir(path) == -1)
{
	perror(path);
	return (98);
}
return (1);
}
