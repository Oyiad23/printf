#include "shell.h"

/**
 * _command - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int _command(kingeso_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * ch_dup - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *ch_dup(char *pathstr, int start, int stop)
{
	static char cushion[1024];
	int kk = 0, k = 0;

	for (k = 0, kk = start; kk < stop; kk++)
		if (pathstr[kk] != ':')
			cushion[k++] = pathstr[kk];
	cushion[k] = 0;
	return (cushion);
}

/**
 * path_file - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *path_file(kingeso_t *info, char *pathstr, char *cmd)
{
	int kk = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && com(cmd, "./"))
	{
		if (_command(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[kk] || pathstr[kk] == ':')
		{
			path = ch_dup(pathstr, curr_pos, kk);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (_command(info, path))
				return (path);
			if (!pathstr[kk])
				break;
			curr_pos = kk;
		}
		kk++;
	}
	return (NULL);
}
