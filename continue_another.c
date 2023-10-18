#include "shell_header_files.h"
/**
 *continue_if - to continue an if statement
 *@position: postion
 *@buffer_size: buffer size
 *@buffer: buffer itself
 *@val: value to be passed
 *Return: nothing
 */
void continue_if(int position, int buffer_size, char *buffer, int val)
{
		if (position >= buffer_size)
		{
			buffer_size += val;
			buffer = realloc(buffer, buffer_size);
			if (!buffer)
			{
				write_to_stderr("ssh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
}
