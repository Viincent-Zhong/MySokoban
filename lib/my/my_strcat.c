/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Write a function that concatenates two strings.
*/

char *my_strcat(char *dest , char  const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        dest[i] = dest[i];
        i = i + 1;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}
