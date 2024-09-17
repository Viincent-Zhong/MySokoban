/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include <ncurses.h>
#include "sokoban.h"
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    soko_map *s_map = malloc(sizeof(soko_map));

    check_malloc(s_map, s_map);
    disp_usage(av, ac);
    s_map->av1 = av[1];
    init_struct(s_map);
    if (check_map(s_map) == 84)
        return 84;
    init_game();
    gameloop(s_map);
    soko_exit(s_map);
    return 0;
}