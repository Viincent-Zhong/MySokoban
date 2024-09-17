/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Write a function that copiesncharacters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i = i + 1;
        if (src[n] != '\0' && i < n) {
            dest[i] = '\0';
        }
    }
    return (dest);
}
