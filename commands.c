#include "shell_header_files.h"

int (*ssh_builtin_command_functions[]) (char **) = {
	&ssh_cd,
	&ssh_help,
	&ssh_exit
};
/**
 *ssh_num_builtins - Built in Functions
 *
 *Return: An integer
 */

int ssh_num_builtins(void)
{
	char *ssh_builtin_commands[] = {
		"cd",
		"help",
		"exit"
	};

	return (sizeof(ssh_builtin_commands) / sizeof(char *));
}

/* Builtin function implementations. */

/**
 *ssh_cd - change directory.
 *@args: args comands read
 *Return: Always returns 1, to continue executing.
 */
int ssh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "ssh: anticipated arg to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("ssh");
		}
	}
	return (1);
}

/**
 *ssh_help - brief Builtin command: print help.
 *@args: List of args.  Not examined.
 *
 *Return: Always returns 1, to continue executing.
 */
int ssh_help(char **args)
{
	char *ssh_builtin_commands[] = {
		"cd",
		"help",
		"exit"
	};
	int sk;
	char *inp[4] = {
		"Sunday/King SSH\n",
		"Type the name of the program and the",
		"Desired arguments, and hit enter.\n",
		"These are built in commands:\n"};
	int x = 0;

	while (x < 4)
	{
		write(1, inp[x], _strlen(inp[x]));
		x++;
	}
	for (sk = 0; sk < ssh_num_builtins(); sk++)
	{
		write(1, ssh_builtin_commands[sk], _strlen(ssh_builtin_commands[sk]));
	}

	char *man = " 'man' for information on other programs.\n";

	write(1, man, _strlen(man));
	return (1);
}
