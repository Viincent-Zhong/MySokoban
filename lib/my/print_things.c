/*
** EPITECH PROJECT, 2020
** print_things
** File description:
** Print
*/

#include <stdarg.h>

int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
void convert(int base, int nbr, char b);

int print_string_int_char(char *s, int x, va_list *list)
{
    char c;
    va_list sdic;

    va_copy(sdic, *list);
    if (s[x + 1] == 's') {
        my_putstr(va_arg(sdic, char *));
        x = x + 2;
    }
    if (s[x + 1] == 'd' || s[x + 1] == 'i') {
        my_put_nbr(va_arg(sdic, int));
        x = x + 2;
    }
    if (s[x + 1] == 'c') {
        my_putchar( c = va_arg(sdic, int));
        x = x + 2;
    }
    va_end(sdic);
    return x;
}

void put_zero(int nbr)
{
    if (nbr < 10)
        my_putstr("\\00");
    if (nbr > 10 && nbr < 100)
        my_putstr("\\0");
    if (nbr > 100)
        my_putchar('\\');
}

void flag_s_uppcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            put_zero(str[i]);
            convert(8, str[i], 'S');
            i = i + 1;
        }
        my_putchar(str[i]);
        i = i + 1;
    }
}
