/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Swaps the content of two integers
*/

int my_swap(int *a, int *b)
{
    int stocka;
    int stockb;
    stocka = *a;
    stockb = *b;
    *a = stockb;
    *b = stocka;
}
