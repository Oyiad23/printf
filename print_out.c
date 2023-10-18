#include "shell_header_files.h"

/**
 *print_out - print string to the standard out
 * @str: string to be printed
 *
 *Return: nothing
 */
void print_out(char *str)
{

	write(STDOUT_FILENO, str, _strlen(str));

}
