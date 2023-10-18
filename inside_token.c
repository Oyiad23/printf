#include "shell_header_files.h"
/**
 *token_evalute - Evaluates token
 *@abs_comm_path: full path
 *@token: Token
 *@args: arguments
 *Return: void
 */
void token_evalute(char *abs_comm_path, char *token, char **args)
		{
			abs_comm_path = (char *)malloc(strlen(token) + strlen(args[0]) + 2);
			if (abs_comm_path == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			copy_cat(abs_comm_path, token, "/", args[0]);
			if (access(abs_comm_path, X_OK) != -1)
			{
				if (execve(abs_comm_path, args, NULL) == -1)
				{
					perror("execve");
					free(abs_comm_path);
					exit(EXIT_FAILURE);
				}
			}
			free(abs_comm_path);
		}
