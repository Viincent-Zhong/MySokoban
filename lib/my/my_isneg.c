/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Displays either N if the int is negative,P if positive or null
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{
    if ( n < 0 ) {
        my_putchar('N');
        my_putchar('\n');
    } if ( n >= 0) {
        my_putchar('P');
        my_putchar('\n');
    }
    return 0;
}
