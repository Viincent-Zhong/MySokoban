/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** Write an recursive function that calculate the power of a number.
*/

unsigned int my_compute_power(int nb, int p)
{
    unsigned long long result = 1;

    for (; p > 0; p--) {
        result = result * nb;
        if (result >= 4294967296)
            return result;
    }
    return result;
}
