#include "shell_header_files.h"
/**
 *get_func - Read line from standard input
 *@inp_line: read into line
 *@buffer_size: size of buffer
 *Return: nothing
 */
char *get_func(char *inp_line, ssize_t buffer_size)

{
	if (getline(&inp_line, &buffer_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("ssh: getline\n");
			exit(EXIT_FAILURE);
		}
	}
	return (inp_line);
}
