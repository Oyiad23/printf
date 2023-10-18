#include "shell_header_files.h"
/**
*main - entry point.
*@argc: Argument count.
*@argv: Argument vector.
*@env: environmental variable
*Return: status code
*/
int main(int argc, char *argv[], char **env __attribute__((unused)))
{
/* Load config files, if any.*/
/* Run command loop.*/
	ssh_loop();

/*Perform any shutdown/cleanup.*/

	return (EXIT_SUCCESS);
}
