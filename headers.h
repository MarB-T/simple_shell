#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int parsing_arg(char *inputstr, ssize_t num_of_chars, char ***argv);
int process_command(char **argv);


#endif
