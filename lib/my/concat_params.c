/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** Turns the command-line given arguments into a single string
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

int my_strlen(char const *str);

int my_putstr(char const *str);

char *my_strcat(char *dest, char const *src);

int get_argv_len(int argc, char **argv)
{
    int i = 0;
    int max;

    while (i < argc) {
        max += my_strlen(argv[i]) + 1;
        i += 1;
    }
    return (max);
}

char *concat_params(int argc, char **argv)
{
    int i = 0;
    char *string = malloc(sizeof(char) * (get_argv_len(argc, argv) + 1));

    while (i < argc) {
        string = my_strcat(string, argv[i]);
        if (i < argc - 1)
            string = my_strcat(string, "\n");
        i = i + 1;
    }
    return (string);
}
