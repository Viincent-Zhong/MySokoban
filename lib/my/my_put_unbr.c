/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Write a function that displays the number given as a parameter.
*/

void my_putchar(char c);

int my_put_unbr(unsigned int nb)
{
    unsigned int reste;

    reste = nb % 10;
    nb = nb / 10;
    if (nb > 0)
        my_put_unbr(nb);
    my_putchar(reste + 48);
}
