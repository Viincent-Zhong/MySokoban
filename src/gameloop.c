/*
** EPITECH PROJECT, 2021
** gameloop
** File description:
** Gameloop
*/

#include "my.h"
#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int win_condition(soko_map *map)
{
    int box = 0;

    for (int i = 0; map->coin_pos[i] != NULL; i++)
        if (map->map[map->coin_pos[i][0]][map->coin_pos[i][1]] == 'X')
            box++;
    if (box == map->coin) {
        clear();
        draw_map(map->map, map);
        refresh();
        usleep(1500000);
        endwin();
        end_screen(map);
        exit(0);
    }
    return 0;
}

void check_stuck_boxes(soko_map *map)
{
    int stuck = 0;

    for (int i = 0;map->map[i] != NULL; i++)
        for (int j = 0;map->map[i][j] != '\0'; j++)
            stuck += check_stuck(map->map, i, j);
    if (stuck == map->boxes) {
        clear();
        draw_map(map->map, map);
        refresh();
        usleep(1500000);
        endwin();
        end_screen(map);
        exit(1);
    }
    map->box_wall = 0;
}

int draw_map_on_screen(soko_map *s_map)
{
    clear();
    refresh();
    if (LINES <= s_map->map_y || COLS < s_map->map_x) {
        mvaddstr((LINES / 2), (COLS / 2) - (18 / 2), "WINDOW TOO SMALL");
        refresh();
        usleep(100000);
        return 1;
    }
    else
        draw_map(s_map->map, s_map);
    return 0;
}

int gameloop(soko_map *s_map)
{
    int key = 0;

    while (1) {
        if (draw_map_on_screen(s_map) == 1)
            continue;
        check_stuck_boxes(s_map);
        win_condition(s_map);
        key = getch();
        if (key == 27)
            break;
        if (key == ' ')
            init_struct(s_map);
        if (move_player(key, s_map) == 1)
            break;
        key = 0;
    }
    return 0;
}