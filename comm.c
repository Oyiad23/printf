#include "shell_header_files.h"
/**
 *ssh_exit - Used to exit shell
 *@args: arguments
 *Return: an integer o for success
 */
int ssh_exit(char **args)
{
	return (0);
}
/**
 *ssh_launch - launches the program
 *@args: Arguments to be passed
 *Return: 1 for program continuity
 */

int ssh_launch(char **args)
{
	pid_t pid;
	int curr_mode;

	pid = fork();
	if (pid == 0)
	{
		char *comm_path = _getenv("PATH");
		char *abs_comm_path = NULL;

		if (comm_path == NULL)
		{
			write_to_stderr("PATH env var not found\n");
		}
		char *token = strtok(comm_path, ":");

		while (token != NULL)
		{
			token_evalute(abs_comm_path, token, args);

			token = strtok(NULL, ":");
		}
		write_to_stderr("Executable file not found in PATH\n");
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pid, &curr_mode, WUNTRACED);
		} while (!WIFEXITED(curr_mode) && !WIFSIGNALED(curr_mode));
	}
	return (1);
}


/**
 * ssh_execute - brief Execute shell built-in or launch program.
 *@args: Null terminated list of arguments.
 *Return: 1 if the shell should continue running, 0 if it should terminate
 */
int ssh_execute(char **args)
{
	char *ssh_builtin_commands[] = {
		"cd",
		"help",
		"exit"
	};
	int sk;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (sk = 0; sk < ssh_num_builtins(); sk++)
	{
		if (strcmp(args[0], ssh_builtin_commands[sk]) == 0)
		{
			return ((*ssh_builtin_command_functions[sk])(args));
		}
	}

	return (ssh_launch(args));
}

/**
 *ssh_read_line - brief Read a line of input from stdin
 *inp_line - command line input
 *Return: The line from stdin.
 */
char *ssh_read_line(void)
{
#ifdef SSH_STD_GETLINE
	char *inp_line = NULL;
	ssize_t buffer_size = 0;

	get_func(inp_line, buffer_size);
#else
#define SSH_BUFFER_SIZE 1024
	int buffer_size = SSH_BUFFER_SIZE;
	int curr_pos = 0;
	char *buffer = malloc(sizeof(char) * buffer_size);
	int kc;

	continue_func(buffer);
	while (1)
	{
		kc = getchar();

		if (kc == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else if (kc == '\n')
		{
			buffer[curr_pos] = '\0';
			return (buffer);
		}
		else
		{
			buffer[curr_pos] = kc;
		}
		curr_pos++;
		continue_if(curr_pos, buffer_size, buffer, SSH_BUFFER_SIZE);
	}
#endif
}
/**
 *ssh_split_line - brief Split a line into tokens
 *@inp_line: The line
 *Return: Null-terminated array of tokens
 */

char **ssh_split_line(char *inp_line)
{
	int buffer_size = SSH_TOKEN_BUFFER_SIZE, curr_pos = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		write_to_stderr("ssh: allocation error\n");
	}

	token = strtok(inp_line, SSH_TOKEN_DELIM);
	while (token != NULL)
	{
		tokens[curr_pos] = token;
		curr_pos++;
		if (curr_pos >= buffer_size)
		{
			buffer_size += SSH_TOKEN_BUFFER_SIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				write_to_stderr("ssh: allocation error\n");
			}
		}

		token = strtok(NULL, SSH_TOKEN_DELIM);
	}
	tokens[curr_pos] = NULL;
	return (tokens);
}

