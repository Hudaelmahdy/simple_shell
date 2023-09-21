#include "shell.h"

/**
 *main - Entry point
 *@argc: count arguments
 *@args: arguments
 *@envarray: env
 *Return: _exit
 */

int main(int argc, char **args, char **envarray)
{
	char *get_command = NULL, **user_command = NULL;
	int value = 0, _exit = 0, n = 0;
	(void)argc;

	while (1)
	{
		get_command = user_input();
		if (get_command)
		{
			value++;
			user_command = get_token(get_command);
			if (!user_command)
			{
				free(get_command);
				continue;
			}
			if ((!str_cmp(user_command[0], "exit")) && user_command[1] == NULL)
				exit_shell(user_command, get_command, _exit);
			if (!str_cmp(user_command[0], "env"))
				get_env(envarray);
			else
			{
				n = evaluate_path(&user_command[0], envarray);
				_exit = fork_function(user_command, args, envarray, get_command, value, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(get_command);
	}
	return (_exit);
}
