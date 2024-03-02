/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_print_map.c
*/

#include "my.h"

void print_map(char **map)
{
    for (int i = 0; map[i]; i++)
        my_printf("%s\n", map[i]);
}
