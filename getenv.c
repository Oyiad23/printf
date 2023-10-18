#include "shell_header_files.h"
/**
 *_getenv - Gets environment variable
 *@name: name of the varaible
 *
 *Return: Returns a string to the value
 */
char *_getenv(const char *name)
{
	if (name == NULL || environ == NULL)
		return (NULL);

	size_t name_len = strlen(name);

	for (char **env = environ; *env != NULL; env++)
	{
		if (strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
			return (&((*env)[name_len + 1]));
	}

	return (NULL);
}
