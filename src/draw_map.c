/*
** EPITECH PROJECT, 2021
** draw_map
** File description:
** Draw the map
*/

#include "my.h"
#include "sokoban.h"
#include <stdlib.h>
#include <ncurses.h>

int draw_color3(char carac, int row, int cols, soko_map *s_map)
{
    if (carac == '#') {
        attron(COLOR_PAIR(4));
        mvaddch((LINES / 2) - (s_map->map_y / 2) + row, (COLS / 2)
        - (s_map->map_x / 2) + cols, carac);
        attroff(COLOR_PAIR(4));
        return 1;
    }
    if (carac == 'O') {
        attron(COLOR_PAIR(2));
        mvaddch((LINES / 2) - (s_map->map_y / 2) + row, (COLS / 2)
        - (s_map->map_x / 2) + cols, carac);
        attroff(COLOR_PAIR(2));
        return 1;
    }
    return 0;
}

int draw_color2(char carac, int row, int cols, soko_map *s_map)
{
    if (carac == 'X') {
        attron(COLOR_PAIR(3));
        mvaddch((LINES / 2) - (s_map->map_y / 2) + row, (COLS / 2)
        - (s_map->map_x / 2) + cols, carac);
        attroff(COLOR_PAIR(3));
        return 1;
    }
    if (carac == 'P') {
        attron(COLOR_PAIR(5));
        mvaddch((LINES / 2) - (s_map->map_y / 2) + row, (COLS / 2)
        - (s_map->map_x / 2) + cols, carac);
        attroff(COLOR_PAIR(5));
        return 1;
    }
    return 0;
}

int draw_color(char carac, int row, int cols, soko_map *s_map)
{
    if (draw_color2(carac, row, cols, s_map) == 1)
        return 1;
    if (draw_color3(carac, row, cols, s_map) == 1)
        return 1;
    attron(COLOR_PAIR(1));
    mvaddch((LINES / 2) - (s_map->map_y / 2) + row, (COLS / 2)
    - (s_map->map_x / 2) + cols, carac);
    attroff(COLOR_PAIR(1));
    return 0;
}

void draw_map(char **map, soko_map *s_map)
{
    for (int row = 0; map[row] != NULL; row++)
        for (int cols = 0; map[row][cols] != '\0'; cols++) {
            draw_color(map[row][cols], row, cols, s_map);
        }
}