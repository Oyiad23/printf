#include "shell_header_files.h"
/**
 *if_congetline - cintinue if conditon
 *@x: integer variable
 *@line_length: len of arguments
 *@inp_line: pointer to char
 *Return: pointer to the characters entered
 */

char *if_congetline(int x, int line_length, char *inp_line)
{
		if (x == EOF || x == '\n')
		{
			if (line_length == 0 && x == EOF)
			{
				return (NULL);
			}
			char *temp = (char *)malloc(line_length + 1);

			if (temp == NULL)
			{
				free(inp_line);
				return (NULL);
			}

			if (inp_line != NULL)
			{
				for (int y = 0; y < line_length; y++)
				{
					temp[y] = inp_line[y];
				}
				free(inp_line);
			}
			inp_line = temp;
			if (x == EOF)
			{
				inp_line[line_length] = '\0';
			}
			else
			{
				inp_line[line_length] = '\n';
				inp_line[line_length + 1] = '\0';
			}
		}
}
