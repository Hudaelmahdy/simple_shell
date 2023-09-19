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
	exit(EXIT_SUCCESS);
}
else
	{
	child_status = waitpid(pid, &status, 0);
	if (child_status < 0)
	{
		free_exit(command);
	}
	else
	{
		free_double_pointer(command);
	}
}
}

/**
*Ch_dir - function to change working directory
*@path: new dir
*Return: 0 on sucess, -1 on failure
*/

int Ch_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;
	int ispathAllocated = 0;

if (path == NULL)
{
	buf = getcwd(buf, size);
	if (buf == NULL)
	{
		perror("getcwd");
		return (98);
	}
	path = buf;
	ispathAllocated = 1;
}
if (chdir(path) == -1)
{
	perror(path);
	if (ispathAllocated)
		free(buf);
	return (98);
}
if (ispathAllocated)
	free(buf);
return (1);
}
