/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string.
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
