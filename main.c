#include "shell.h"

/**
*main - Entry point.
*@argc: numbers of arguments
*@argv: vector of arguments
*@env: pointer to enviromental variable.
*Return: 0
*/


int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	int cycles = 0;
	(void)argc;

while (1)
{
	cycles++;
	prompt();
	signal(SIGINT, handle);
	chars_readed = getline(&buffer, &buf_size, stdin);
	if (chars_readed == EOF)
	_EOF(buffer);
	else if (*buffer == '\n')
		free(buffer);
	else
	{
		buffer[strlen(buffer) - 1] = '\0';
		command = tokening(buffer, '\0');
		free(buffer);
		if (strcmp(command[0], "exit") != 0)
		exit(command);
		else if (strcmp(command[0], "cd") != 0)
			ch_dir(command[1]);
		else
				child(command, argv[0], env, cycles);
	}
	fflush(stdin);
	buffer = NULL, buf_size = 0;
}
if (chars_readed == -1)
	return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
}

/**
*prompt - function to print prompt
*Return: nothing
*/

void prompt(void)
{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "simple_shell", 13);
}

/**
*handle- function to handle signal
*@sig: signal
*Return: nothing
*/

void handle(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nsimple_shell", 14);
}

/**
*_EOF - function to check end of file
*@buffer: pointer to string
*Return: nothing
*
*/
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer =  NULL;
	}

if (isatty(STDIN_FILENO))
{
	write(STDOUT_FILENO, '\n', 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
*exit - function to exit shell
*@command: pointer to command
*Return: nothing
*/

void exit(char **command)
{
	int exit_status = 0;

if (command[1] == NULL)
	free_double_pointer(command);
	exit(EXIT_SUCCESS);
exit_status = _atoi(command[1]);
free_double_pointer(command);
exit(exit_status);
}
