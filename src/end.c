/*
** EPITECH PROJECT, 2021
** end
** File description:
** Deal with the end of the game
*/

#include "my.h"
#include "sokoban.h"
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

void end_screen(soko_map *map)
{
    for (int i = 0;map->coin_pos != NULL && map->coin_pos[i] != NULL; i++)
        free(map->coin_pos[i]);
    if (map->coin_pos != NULL)
        free(map->coin_pos);
    if (map != NULL)
        free(map);
}