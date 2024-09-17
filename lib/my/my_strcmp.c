/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Reproduce the behavior of thestrcmpfunction.
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i])
            return 1;
        if (s2[i] > s1[i])
            return -1;
        while (s1[j] == s2[j]) {
            j = j + 1;
            if (s1[j] == '\0' && s2[j] == '\0')
                return 0;
        }

        i = i + 1;
    }
}
