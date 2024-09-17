/*
** EPITECH PROJECT, 2021
** stuck
** File description:
** Stuck
*/

#include "my.h"
#include "sokoban.h"
#include <ncurses.h>

int check_stuck(char **map, int i, int j)
{
    int stuck_wall = 0;

    if (map[i][j] == 'X') {
        if (map[i - 1] == NULL || map[i + 1] == NULL)
            stuck_wall = 1;
        if ((map[i - 1][j] == '#' || map[i - 1][j] == 'X') ||
        (map[i + 1][j] == '#' || map[i + 1][j] == 'X'))
            stuck_wall = 1;
        if (stuck_wall == 1 && ((map[i][j - 1] == '#' || map[i][j - 1] == 'X'
        || map[i][j - 1] == '\0') || (map[i][j + 1] == '#' ||
        map[i][j + 1] == 'X' || map[i][j + 1] == '\0')))
            return 1;
    }
    return 0;
}