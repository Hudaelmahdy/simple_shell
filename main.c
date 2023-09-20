#include "shell.h"

/**
 * sig_handler - signal handler for SIGINT signal that checks ctrl+c if pressed
 * @num: int
*/
void sig_handler(int num)
{
	if (num == SIGINT)
	{
		_puts("\n#simple_shell_project$ ");
	}
}

/**
 * _EOF - function that handling the End Of File
 * @chars_readed: return getline unction value
 * @buffer: buffer
*/
void _EOF(int chars_readed, char *buffer)
{
	(void)buffer;
	if (chars_readed == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}

/**
 * isatty - checks if standard input is terminal
*/
void_isatty(void)
{
	if (isatty(STDIN_FILENO))
	{
		_puts("#simple_shell_project$ ");
	}
}


/**
*main - shell
*Return: 0
*/

int main(void)
{
	char *buffer = NULL, *value, *pname, **argv;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	ls_path *firstNode = '\0';
	 void (*f)(char **);
signal(SIGINT, sig_handler);
while (chars_readed != EOF)
{
	_isatty();
	chars_readed = getline(&buffer, &buf_size, stdin);
	_EOF(chars_readed, buffer);
	argv = tokenizeString(buffer, " \n");
	if (!argv || !argv[0])
		execute(argv);
	else
	{
		value = get_env("PATH");
		firstNode = pathlink(value);
		pname = locate_command(argv[0], firstNode);
		f = lookup_builtin(argv);
		if (f)
		{
			free(buffer);
			f(argv);
		}
		else if (!pname)
			execute(argv);
		else if (pname)
		{
			free(argv[0]);
			argv[0] = pname;
			execute(argv);
		}
	}
}
free_ls(firstNode);
freeargv(argv);
free(buffer);
return (0);
}
