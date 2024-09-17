/*
** EPITECH PROJECT, 2021
** move_player
** File description:
** Move the player
*/

#include "my.h"
#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>

void deal_coin(soko_map *map)
{
    char to_check;

    for (int i = 0; map->coin_pos[i] != NULL; i++) {
        to_check = map->map[map->coin_pos[i][0]][map->coin_pos[i][1]];
        if (to_check != 'O' && to_check != 'P' && to_check != 'X')
            map->map[map->coin_pos[i][0]] [map->coin_pos[i][1]] = 'O';
    }
}

int check(soko_map *map, int decre_x, int decre_y)
{
    int value = 0;

    map->decre_x = decre_x;
    map->decre_y = decre_y;
    if (map->map[map->pp_x + decre_x] == NULL)
        return 84;
    if (map->map[map->pp_x + decre_x][map->pp_y + decre_y] == '#' ||
    map->map[map->pp_x + decre_x][map->pp_y + decre_y] == '\0')
        return 84;
    if (map->map[map->pp_x + decre_x][map->pp_y + decre_y] == 'X') {
        value = move_box(map, map->pp_x + decre_x, map->pp_y + decre_y);
        if (value == 84)
            return 84;
        else if (value == 1)
            return 1;
    }
    map->map[map->pp_x][map->pp_y] = ' ';
    deal_coin(map);
    return 0;
}

int move_player(int key, soko_map *map)
{
    int value = move_down(key, map) + move_left(key, map)
    + move_right(key, map) + move_up(key, map);

    if (value > 0 && value < 5)
        return 1;
    if (value >= 84)
        return 0;
    return 0;
}