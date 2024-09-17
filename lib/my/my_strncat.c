/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** Concatenatesncharacters of the src string to the end of thedest string
*/

char *my_strncat(char *dest , char  const *src , int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] !='\0')
        i = i + 1;
    while (src[j] != '\0' && j < nb) {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}
