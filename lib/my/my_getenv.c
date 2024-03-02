/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_getenv.c
*/

#include "my.h"

char *my_getenv(char **envp, char *name)
{
    int name_length = my_strlen(name);

    for (int i = 0; envp[i]; i++)
        if (my_strncmp(envp[i], name, name_length) == 0 &&
        envp[i][name_length] == '=')
            return envp[i] + name_length + 1;
    return NULL;
}
