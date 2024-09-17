/*
** EPITECH PROJECT, 2021
** deal_box
** File description:
** Deal with the boxes like the movement of the box
*/

#include "my.h"
#include "sokoban.h"
#include <stdlib.h>
#include <ncurses.h>

int check_box(soko_map *map, int b_x, int b_y)
{
    if (map->map[b_x] == NULL) {
        map->box_wall++;
        return 84;
    }
    else if (map->map[b_x][b_y] == '#' || map->map[b_x][b_y] == '\0') {
        map->box_wall++;
        return 84;
    }
    if (map->map[b_x][b_y] == 'X')
        return 84;
    map->map[b_x][b_y] = ' ';
    deal_coin(map);
    return 0;
}

int move_box(soko_map *map, int b_x, int b_y)
{
    if (check_box(map, b_x + map->decre_x, b_y + map->decre_y) == 84)
        return 84;
    map->map[b_x + map->decre_x][b_y + map->decre_y] = 'X';
    return 0;
}