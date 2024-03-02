/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_maplen.c
*/

#include "my.h"

int my_maplen(char **map)
{
    int len = 0;

    for (; map[len]; len++);
    return len;
}
