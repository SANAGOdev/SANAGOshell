/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** error_handling.c
*/

#include "my.h"
#include "minishell.h"

void error_handling(char *args)
{
    if (errno == EACCES)
        my_printf("%s: Permission denied.\n", args);
}
