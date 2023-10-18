#include "shell_header_files.h"

/**
 *ssh_loop - getting input and executing it
 */
void ssh_loop(void)
{
	char *inp_line;
	char **args;
	int curr_mode;

	do {
		print_out("($) ");
		inp_line = ssh_read_line();
		args = ssh_split_line(inp_line);
		curr_mode = ssh_execute(args);
		free(inp_line);
		free(args);
	} while (curr_mode);
}
