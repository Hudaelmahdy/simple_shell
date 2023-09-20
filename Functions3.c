#include "shell.h"

/**
*get_env - get the value of enviromental variable
*@name: name of env
*Return: value
*/

char *get_env(const char *name)
{
	int i, j;

	char *value;

	if (!name)
		return (NULL);
	for (i = 0; env_array[i]; i++)
	{
		j = 0;
		if (name[j] == env_array[i][j])
		{
			while (name[j])
			{
				if (name[j] != env_array[i][j])
					break;
				j++;
			}
			if (name[j] == '\0')
			{
				value = (env_array[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}


/**
*push_node - add new node to the linked list
*@firstNode: double pointer to the head
*@str: pointer to string to be stored in the new node
*Return: address of
*/

ls_path *push_node(ls_path **firstNode, char *str)
{
	ls_path *tmp;
	ls_path *new;

	new = malloc(sizeof(ls_path));
	if (!new || !str)
	{
		return (NULL);
	}

	new->directory = str;

	new->next_dir = '\0';

	if (!*firstNode)
	{
		*firstNode = new;
	}
	else
	{
		tmp = *firstNode;
		while (tmp->next_dir)
		{
			tmp = tmp->next_dir;
		}
		tmp->next_dir = new;
	}
	return (*firstNode);
}

/**
*pathlink- create link for path
*@pathstr: string of path
*Return: pointer to linked list
*/

ls_path *pathlink(char *pathstr)
{
	ls_path *firstNode = '\0';

	char *path_segment;

	char *copied_path = _strdup(pathstr);

	path_segment = strtok(copied_path, ":");
	while (path_segment)
	{
		firstNode = push_node(&firstNode, path_segment);
		path_segment = strtok(NULL, ":");
	}

	return (firstNode);
}


/**
*locate_command - function to find full path of a command
*@command_name: name of command
*@firstNode: name of head node that links directories
*Return: path or NULL on failure
*/

char *locate_command(char *command_name, ls_path *firstNode)
{
	struct stat check;
	char *fullpath;

	ls_path *tmp = firstNode;

	while (tmp)
	{
		fullpath = concat(tmp->directory, "/", command_name);
		if (stat(fullpath, &check) == 0)
		{
			return (fullpath);
		}
		free(fullpath);
		tmp = tmp->next_dir;
	}
	return (NULL);
}

/**
 *free_ls - frees the linkedlist
 *@firstNode: pointer to head node
*/

void free_ls(ls_path *firstNode)
{
	ls_path *temp_node;

	while (firstNode)
	{
		temp_node = firstNode->next_dir;
		free(firstNode->directory);
		free(firstNode);
		firstNode = temp_node;
	}
}
