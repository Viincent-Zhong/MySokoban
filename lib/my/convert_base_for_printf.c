/*
** EPITECH PROJECT, 2020
** convert_base_for_printf
** File description:
** Convert into hexa, octa or binary base
*/

#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_compute_power(int nb, int p);
int my_put_unbr(unsigned int nb);

void syntax_hexa(int nbr, int base, int up_low)
{
    if (nbr >= 10) {
        if (nbr == 10)
            my_putchar(97 - up_low);
        if (nbr == 11)
            my_putchar(98 - up_low);
        if (nbr == 12)
            my_putchar(99 - up_low);
        if (nbr == 13)
            my_putchar(100 - up_low);
        if (nbr == 14)
            my_putchar(101 - up_low);
        if (nbr == 15)
            my_putchar(102 - up_low);
    }
    else
        my_put_unbr(nbr);
}

void convert(int base, unsigned int nbr, char b)
{
    int power = 0;

    while (nbr > my_compute_power(base, power) &&
            my_compute_power(base, power) != 0)
        power = power + 1;
    power = power - 1;
    for (unsigned int mod = nbr, stock = nbr; power >= 0; power--) {
        nbr = mod / my_compute_power(base, power);
        mod = stock % my_compute_power(base, power);
        if (b == 'x')
            syntax_hexa(nbr, base, 0);
        else if (b == 'X')
            syntax_hexa(nbr , base, 32);
        else
            my_put_unbr(nbr);
        stock = mod;
    }
}

int convert_base(char *s, int x, va_list *list)
{
    va_list nbr;
    unsigned int conv;

    va_copy(nbr, *list);
    if (s[x + 1] == 'x' || s[x + 1] == 'o' || s[x + 1] == 'b' ||
        s[x + 1] == 'X') {
        conv = va_arg(nbr, unsigned int);
        x = x + 2;
    }
    if (s[x - 1] == 'x')
        convert(16, conv, s[x - 1]);
    if (s[x - 1] == 'o')
        convert(8, conv, s[x - 1]);
    if (s[x - 1] == 'b')
        convert(2, conv, s[x - 1]);
    if (s[x - 1] == 'X')
        convert(16, conv, s[x - 1]);
    va_end(nbr);
    return x;
}
