/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** system_cmd.c
*/

#include "my.h"
#include "minishell.h"

void system_cmd(char **arg_list, char **env)
{
    int status = 0;
    pid_t pid = fork();

    if (pid < 0)
        perror("fork");
    if (pid == 0) {
        system_functions(arg_list, env);
        exit(1);
    } else {
        wait(&status);
        handle_segfault(status);
    }
}

void system_functions(char **arg_list, char **env)
{
    char *path;

    path = get_valid_path(arg_list[0], env);
    if (execve(path, arg_list, env) == -1)
        error_handling(arg_list[0]);
}

void handle_segfault(int status)
{
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
        my_printf("Segmentation fault\n");
}
