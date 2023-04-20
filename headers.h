#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

int parsing_arg(char *inputstr, size_t num_of_chars, char ***argv);
int process_command(char **argv);
char *get_location(char *cmd);
char *_getenv(const char *name);
void shell_exit(void);
void error_msg(int error_code);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif
