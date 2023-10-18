#include "shell_header_files.h"
/**
 *copy_cat - copy and concatenate
 *@full_path: full path to command
 *@token: Tokenized string
 *@forward_slash: divider
 *@args: Arguments
 *
 *Return: void
 */
void copy_cat(char *full_path, char *token, char *forward_slash, char *args)
{
			_strcpy(full_path, token);
			_strcat(full_path, forward_slash);
			_strcat(full_path, args);


}
