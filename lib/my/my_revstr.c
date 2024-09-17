/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** Write a function that reverses a string.
*/

char *my_revstr(char *str)
{
    int i = 0;
    int a = 0;
    int b;
    int stock;

    while (str[i] != '\0') {
        i = i + 1;
    }
    b = i - 1;
    while (b > a) {
        stock = str[a];
        str[a] = str[b];
        str[b] = stock;
        b = b - 1;
        a = a + 1;
    }
    return (str);
}
