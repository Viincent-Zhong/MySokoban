/*
** EPITECH PROJECT, 2021
** macro
** File description:
** Macro
*/

#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

void check_malloc(void *anything, soko_map *map)
{
    if (anything == NULL) {
        end_screen(map);
        exit(84);
    }
}