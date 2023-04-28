


int execute_file_commands(char *filename, int *exit_ptr) {
    int exit_status = 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return exit_status;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        exit_status = process_arguments(exit_ptr, line);
        if (exit_status == END_OF_FILE || exit_status == EXIT) {
            break;
        }
    }

    free(line);
    fclose(fp);
    return exit_status;
}






int execute(char **args, char **front)
{
    pid_t child_pid;
    int status, flag = 0, ret = 0;
    char *command = args[0];

    if (command[0] != '/' && command[0] != '.')
    {
        flag = 1;
        command = get_location(command);
    }

    if (!command || (access(command, F_OK) == -1))
    {
        if (errno == EACCES)
            ret = (create_error(args, 126));
        else
            ret = (create_error(args, 127));
    }
    else
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            if (flag)
                free(command);
            perror("Error child:");
            return (1);
        }
        if (child_pid == 0)
        {
            execve(command, args, environ);
            if (errno == EACCES)
                ret = (create_error(args, 126));
            free_env();
            free_args(args, front);
            free_alias_list(aliases);
            _exit(ret);
        }
        else
        {
            wait(&status);
            ret = WEXITSTATUS(status);
        }
    }
    if (flag)
        free(command);
    return (ret);
}

