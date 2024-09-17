/*
** EPITECH PROJECT, 2021
** direction_move
** File description:
** Direction move
*/

#include "my.h"
#include <ncurses.h>
#include "sokoban.h"

int move_left(int key, soko_map *map)
{
    int value = 0;

    if (key == KEY_LEFT) {
        value = check(map, 0, -1);
        if (value == 84)
            return 84;
        else if (value == 1)
            return 1;
        map->map[map->pp_x][map->pp_y - 1] = 'P';
        map->pp_y -= 1;
    }
    return 0;
}

int move_right(int key, soko_map *map)
{
    int value = 0;

    if (key == KEY_RIGHT) {
        value = check(map, 0, 1);
        if (value == 84)
            return 84;
        else if (value == 1)
            return 1;
        map->map[map->pp_x][map->pp_y + 1] = 'P';
        map->pp_y += 1;
    }
    return 0;
}

int move_up(int key, soko_map *map)
{
    int value = 0;

    if (key == KEY_UP) {
        value = check(map, -1, 0);
        if (value == 84)
            return 84;
        else if (value == 1)
            return 1;
        map->map[map->pp_x - 1][map->pp_y] = 'P';
        map->pp_x -= 1;
    }
    return 0;
}

int move_down(int key, soko_map *map)
{
    int value = 0;

    if (key == KEY_DOWN) {
        value = check(map, 1, 0);
        if (value == 84)
            return 84;
        else if (value == 1)
            return 1;
        map->map[map->pp_x + 1][map->pp_y] = 'P';
        map->pp_x += 1;
    }
    return 0;
}