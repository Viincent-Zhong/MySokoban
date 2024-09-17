/*
** EPITECH PROJECT, 2020
** disp_stdarg
** File description:
** Disp starg
*/

#include <stdarg.h>

int my_putstr(char const *str);
void my_putchar(char c);
void convert(int base, int nbr, char b);
int convert_base(char *s, int x, va_list *list);
int print_string_int_char(char *s, int x, va_list *list);
void flag_s_uppcase(char *str);
int my_put_unbr(unsigned int nb);
int my_put_nbr(int nb);

int check_flag(char *s, int x)
{
    if (s[x] == '%') {
        if (s[x + 1] != 'b' && s[x + 1] != 's' && s[x + 1] != 'c' &&
            s[x + 1] != 'd' && s[x + 1] != 'i' && s[x + 1] != 'p' &&
            s[x + 1] != 'u' && s[x + 1] != 'x' && s[x + 1] != 'X' &&
            s[x + 1] != '%' && s[x + 1] != 'S' && s[x + 1] != 'o' &&
            s[x + 1] != '#' && s[x + 2] != 'x' && s[x + 2] != 'X' &&
            s[x + 2] != 'b' && s[x + 2] != 'o') {
            my_putchar(s[x]);
            x = x + 1;
        }
        if (s[x + 1] == '%') {
            my_putchar(s[x]);
            x = x + 2;
        }
    }
    return x;
}

int other(char *s, int x, va_list *list)
{
    va_list adress;
    char *str;

    va_copy(adress, *list);
    if (s[x + 1] == 'p') {
        my_putstr("0x");
        convert(16, va_arg(adress, int), 'x');
        x = x + 2;
    }
    if (s[x + 1] == 'S') {
        str = va_arg(adress, char *);
        flag_s_uppcase(str);
        x = x + 2;
    }
    if (s[x + 1] == 'u') {
        my_put_unbr(va_arg(adress, unsigned int));
        x = x + 2;
    }
    return x;
}

int strange_flag(char *s, int x, va_list *list)
{
    va_list flag;

    va_copy(flag, *list);
    if (s[x + 1] == '#' && (s[x + 2] == 'x' || s[x + 2] == 'X' ||
                            s[x + 2] == 'o' || s[x + 2] == 'b')) {
            my_putstr("0x");
            x = x + 3;
        }
    if (s[x - 2] == '#' && s[x - 1] == 'x')
        convert(16, va_arg(flag, int), 'x');
    if (s[x - 2] == '#' && s[x - 1] == 'X')
        convert(16, va_arg(flag, int), 'X');
    if (s[x - 2] == '#' && s[x - 1] == 'o')
        convert(8, va_arg(flag, int), 'o');
    if (s[x - 2] == '#' && s[x - 1] == 'b')
        convert(2, va_arg(flag, int), 'b');
    return x;
}

void my_printf(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int x = 0; s[x] != '\0';) {
        if (s[x] != '%') {
            my_putchar(s[x]);
            x = x + 1;
        }
        x = check_flag(s, x);
        if (s[x] == '%') {
            x = print_string_int_char(s, x, &list);
            x = convert_base(s, x, &list);
            x = other(s, x, &list);
            x = strange_flag(s, x, &list);
            va_arg(list, int);
        }
    }
    va_end(list);
}
