/*
** EPITECH PROJECT, 2021
** save_coins
** File description:
** Save coins pos
*/

#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

int save_coin_pos(soko_map *map, int k, int i, int j)
{
    map->coin_pos[k][0] = i;
    map->coin_pos[k][1] = j;
    map->coin_pos[k][2] = 0;
    k++;
    return k;
}

void save_coins_pos(soko_map *map)
{
    int i = 0;
    int k = 0;

    map->coin_pos = malloc(sizeof(int *) * (map->coin + 1));
    check_malloc(map->coin_pos, map);
    for (int j = 0; map->map[i] != NULL; j++) {
        if (map->map[i][j] == 'O') {
            map->coin_pos[k] = malloc(sizeof(int) * 3);
            check_malloc(map->coin_pos[k], map);
            k = save_coin_pos(map, k, i, j);
        }
        if (map->map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    map->coin_pos[k] = NULL;
    map->map[i] = NULL;
}

void get_nbr_coins(soko_map *map)
{
    for (int i = 0, j = 0; map->map[i] != NULL; j++) {
        if (map->map[i][j] == 'O')
            map->coin++;
        if (map->map[i][j] == 'X')
            map->boxes++;
        if (map->map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    save_coins_pos(map);
}