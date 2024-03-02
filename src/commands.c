/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cmd_env.c
*/

#include "my.h"
#include "minishell.h"

void cmd_cd(char **arg_list, char **env)
{
    int res = 0;
    char *home_path = my_getenv(env, "HOME");

    if (arg_list[1] == NULL || my_strcmp(arg_list[1], "~") == 0) {
        res = chdir(home_path);
        return;
    }
    if (arg_list[1] != NULL)
        res = chdir(arg_list[1]);
    if (res)
        my_printf("%s: No such file or directory\n", arg_list[1]);
}

void cmd_exit(void)
{
    pid_t process_pid = getpid();

    kill(process_pid, EXIT_SUCCESS);
    exit(0);
}

void cmd_setenv(char **arg_list, char **env)
{
    int nb_args = my_maplen(arg_list);

    if (nb_args == 1) {
        print_map(env);
        return;
    }
    if (nb_args > 3) {
        my_printf("setenv: Too many arguments.\n");
        return;
    }
}
