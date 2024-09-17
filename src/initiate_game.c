/*
** EPITECH PROJECT, 2021
** initiate_game
** File description:
** Initiate the game
*/

#include "my.h"
#include "sokoban.h"
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

void soko_exit(soko_map *map)
{
    endwin();
    end_screen(map);
    exit(84);
}

int check_invalid_char(soko_map *map, int i, int j)
{
    if (map->map[i][j] != 'P' && map->map[i][j] != 'X' &&
    map->map[i][j] != '#' && map->map[i][j] != ' ' &&
    map->map[i][j] != 'O' && map->map[i][j] != '\0')
        return 10;
    return 0;
}

void get_player_pos(soko_map *map)
{
    int player = 0;

    for (int i = 0, j = 0;map->map[i] != NULL; j++) {
        if (map->map[i][j] == 'P') {
            map->pp_x = i;
            map->pp_y = j;
            player++;
        }
        player += check_invalid_char(map, i, j);
        if (map->map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    if (player > 1)
        soko_exit(map);
}

void init_struct(soko_map *s_map)
{
    s_map->box_wall = 0;
    s_map->map_x = 0;
    s_map->map_y = 0;
    s_map->boxes = 0;
    create_map(s_map);
    get_player_pos(s_map);
    s_map->coin = 0;
    get_nbr_coins(s_map);
}

void init_game(void)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(3, COLOR_GREEN, COLOR_BLUE);
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_YELLOW, COLOR_BLUE);
    init_pair(5, COLOR_RED, COLOR_BLUE);
}