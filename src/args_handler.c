/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** handle_arguments.c
*/

#include "my.h"
#include "minishell.h"

void args_handler(char **arg_list, char **env)
{
    if (commands_handler(arg_list, env) != 0)
        system_cmd(arg_list, env);
}

int commands_handler(char **arg_list, char **env)
{
    if (my_strcmp(arg_list[0], "cd") == 0) {
        cmd_cd(arg_list, env);
        return 0;
    }
    if (my_strcmp(arg_list[0], "env") == 0) {
        print_map(env);
        return 0;
    }
    if (my_strcmp(arg_list[0], "setenv") == 0) {
        cmd_setenv(arg_list, env);
        return 0;
    }
    if (my_strcmp(arg_list[0], "exit") == 0) {
        cmd_exit();
        return 0;
    }
    return 1;
}
