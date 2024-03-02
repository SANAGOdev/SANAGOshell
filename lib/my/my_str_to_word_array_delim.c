/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** zmy_str_to_word_array_delim.c
*/

#include "my.h"

static int end_word(char s, char *pat)
{
    for (int i = 0; pat[i]; i++) {
        if (s == pat[i])
            return -1;
    }
    return 0;
}

static int word(const char *str, int i, char *path)
{
    if (end_word(str[i], path) == -1) {
        for (; end_word(str[i], path) == -1; i++);
        i -= 1;
    }
    return i;
}

static int count_y(const char *str, char *pat)
{
    int n = 1;

    for (int i = 0; str[i]; i++) {
        i = word(str, i, pat);
        n += 1;
    }
    return n;
}

static int count_x(const char *str, int i, char *pat)
{
    int len = 0;

    for (; end_word(str[i], pat) == 0 && str[i]; len++) {
        i++;
    }
    return len;
}

char **my_tab(char **tab, int y)
{
    tab[y] = NULL;
    return tab;
}

char **my_str_to_word_array_delim(const char *str, char *pat)
{
    int nb_word = count_y(str, pat) + 2;
    int i = 0;
    char **tab;
    int y = 0;
    int x = 0;

    tab = malloc(sizeof(char *) * nb_word + 1);
    while (str[i]) {
        x = 0;
        for (; end_word(str[i], pat) == -1 && str[i]; i++);
        tab[y] = malloc(sizeof(char) * (count_x(str, i, pat) + 1));
        for (; end_word(str[i], pat) == 0 && str[i]; i++) {
            tab[y][x] = str[i];
            x++;
        }
        tab[y][x] = '\0';
        y++;
        for (; end_word(str[i], pat) == -1 && str[i]; i++);
    }
    return my_tab(tab, y);
}
