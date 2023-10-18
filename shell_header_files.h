#ifndef SHELL_HEADER_FILES_H
#define SHELL_HEADER_FILES_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SSH_TOKEN_BUFFER_SIZE 64
#define SSH_TOKEN_DELIM " \t\r\n\a"

extern char **environ;
int ssh_cd(char **args);
int ssh_help(char **args);
int ssh_exit(char **args);
int ssh_num_builtins(void);
extern int (*ssh_builtin_command_functions[3]) (char **);
int ssh_launch(char **args);
int ssh_execute(char **args);
char *ssh_read_line(void);
char **ssh_split_line(char *inp_line);
void ssh_loop(void);
void continue_if(int position, int buffer_size, char *buffer, int val);
void continue_func(char *buffer);
char *get_func(char *inp_line, ssize_t buffer_size);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
void write_to_stderr(char *str);
void copy_cat(char *full_path, char *token, char *forward_slash, char *args);
void token_evalute(char *abs_comm_path, char *token, char **args);
char *_getenv(const char *name);
char *if_congetline(int x, int line_length, char *inp_line);
void print_out(char *str);

#endif /* SHELL_HEADER_FILES_H GUIDED */
