/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** bin_path_handler.c
*/

#include "my.h"
#include "minishell.h"

char *get_valid_path(char *command, char **env)
{
    char *full_path = NULL;

    for (int i = 0; env[i]; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
        && env[i][3] == 'H')
            full_path = cut_paths(env[i], command);
    }
    return full_path;
}

char *cut_paths(char *env_path, char *command)
{
    char *env_list = NULL;
    char **path_list = NULL;
    int nb_path = 0;

    strtok_r(env_path, "=", &env_list);
    path_list = my_str_to_word_array_delim(env_list, ":");
    while (path_list[nb_path])
        nb_path++;
    return check_accurate_path(path_list, command, nb_path);
}

char *check_accurate_path(char **path_list, char *command, int nb_path)
{
    int fd = 0;
    char *full_path = malloc(sizeof(char) * my_strlen(command) + 2);
    char *good_path;
    int flag = 0;

    full_path[0] = '/';
    my_strcat(full_path, command);
    for (int i = 0; i < nb_path; i++) {
        my_strcat(path_list[i], full_path);
        fd = open(path_list[i], O_RDONLY);
        if (fd != -1) {
            flag = 1;
            good_path = malloc(sizeof(char) * my_strlen(path_list[i]) + 1);
            my_strcpy(good_path, path_list[i]);
            break;
        }
    }
    if (flag == 0)
        my_printf("%s: command not found\n", command);
    return good_path;
}
