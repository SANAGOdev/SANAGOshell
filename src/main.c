/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main.c
*/

#include "my.h"
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    char *buffer;
    size_t buffsize = 32;
    ssize_t nb_char_read = 0;

    if (argc != 1 || argv[1] != NULL)
        return 84;
    if (isatty(STDIN_FILENO))
        main_loop(buffer, buffsize, env);
    else {
        nb_char_read = getline(&buffer, &buffsize, stdin);
        read_loop(nb_char_read, buffer, buffsize, env);
    }
    return 0;
}

void main_loop(char *buffer, size_t buffsize, char **env)
{
    ssize_t nb_char_read = 0;

    while (1) {
        if (isatty(STDIN_FILENO))
            my_printf("\x1b[36m>%s\033[0m\n$> ", getcwd(NULL, 0));
        nb_char_read = getline(&buffer, &buffsize, stdin);
        if (nb_char_read == -1)
            break;
        if (nb_char_read != 1) {
            buffer[nb_char_read - 1] = '\0';
            args_handler(my_str_to_word_array_delim(buffer, "\t "), env);
        }
    }
}

void read_loop(ssize_t nb_char_read, char *buffer,
    size_t buffsize, char **env)
{
    while (nb_char_read != -1) {
        if (nb_char_read != 1) {
            buffer[nb_char_read - 1] = '\0';
            args_handler(my_str_to_word_array_delim(buffer, "\t "), env);
        }
        nb_char_read = getline(&buffer, &buffsize, stdin);
    }
}
