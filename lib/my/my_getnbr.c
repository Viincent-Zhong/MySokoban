/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Write a function that returns a number, sent to the function as a string.
*/

int calculate_nbr(char const *str, int i)
{
    long nb = 0;

    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        nb = nb * 10;
        nb = nb + (str[i] - 48);
        i = i + 1;
        if (nb < -2147483647 || nb > 2147483647)
            return 0;
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int minus = 0;
    long nb = 0;

    while (str[i] < '0' && str[i] != '\0' || str[i] > '9' && str[i] != '\0') {
        if (str[i] == '-')
            minus = minus + 1;
        if (str[i] != '-' && str[i] != '+' && str[i] < '0' || str[i] > '9')
            return 0;
        i = i + 1;
    }
    minus = minus % 2;
    nb = calculate_nbr(str, i);
    if (minus != 0)
        return (-nb);
    return (nb);
}
