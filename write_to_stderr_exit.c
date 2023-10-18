#include "shell_header_files.h"
/**
 *write_to_stderr - write to stderr
 *@str: string to be written
 *
 *Return: nothing
 */
void write_to_stderr(char *str)
{

write(2, str, _strlen(str));
exit(EXIT_FAILURE);
}
