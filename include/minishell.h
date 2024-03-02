/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    /* Library include */
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <errno.h>

    /* Project macros */
    #define MAX_ARGS 20

    /* Project functions */
void main_loop(char *buffer, size_t buffsize, char **env);
void read_loop(ssize_t nb_char_read, char *buffer,
    size_t buffsize, char **env);
int commands_handler(char **arg_list, char **env);
void args_handler(char **arg_list, char **env);

    /* System cmd */
void handle_segfault(int status);
void error_handling(char *args);
char *get_valid_path(char *command, char **env);
char *check_accurate_path(char **path_list, char *command, int nb_path);
char *cut_paths(char *env_path, char *command);
void system_cmd(char **arg_list, char **env);
void system_functions(char **arg_list, char **env);

    /* Commands functions */
void cmd_cd(char **arg_list, char **env);
void cmd_setenv(char **arg_list, char **env);
void cmd_exit(void);

#endif /* !MINISHELL_H_ */
