#include "shell_header_files.h"
/**
 *_getline - getline from the terminal
 *Return: characters to the line
 */
char *_getline(void)
{
	char *inp_line = NULL;
	int line_length = 0, x;

	while (1)
	{
	x = getchar();

		if (x == EOF || x == '\n')
			if_congetline(x, line_length, inp_line);
		else
		{
			char *temp = (char *)malloc(line_length + 2);

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
			inp_line[line_length] = (char)x;
			line_length++;
			inp_line[line_length] = '\0';
		}
	}
}

