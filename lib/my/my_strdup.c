/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Allocates memory and copies the string given as argument in it.
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    int max;
    int j = 0;

    max = my_strlen(src);
    str = malloc(sizeof(char) * (max + 1));
    while (j < max) {
        str[j] = src[j];
        j = j + 1;
    }
    return (str);
}
