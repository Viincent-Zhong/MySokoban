/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** Header file sokoban
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

typedef struct game_map {
    char **map;
    int pp_y;
    int pp_x;
    int decre_x;
    int decre_y;
    int coin;
    int boxes;
    int **coin_pos;
    int map_x;
    int map_y;
    int box_wall;
    char *av1;
}soko_map;

int check_map(soko_map *map);
void check_malloc(void *anything, soko_map *map);
void disp_usage(char **av, int ac);
int win_condition(soko_map *map);
int gameloop(soko_map *s_map);
void end_screen(soko_map *map);
void deal_coin(soko_map *map);
void init_struct(soko_map *s_map);
void init_game(void);
int move_box(soko_map *map, int b_x, int b_y);
void draw_map(char **map, soko_map *s_map);
char *get_buffer(char *buffer, int size, int fd);
int open_file(char const *filepath);
void create_map(soko_map *map);
void check_stuck_boxes(soko_map *map);
void get_nbr_coins(soko_map *map);
void save_coins_pos(soko_map *map);
int check_stuck(char **map, int i, int j);
int move_left(int key, soko_map *map);
int move_right(int key, soko_map *map);
int move_up(int key, soko_map *map);
int move_down(int key, soko_map *map);
int move_player(int key, soko_map *map);
int check(soko_map *map, int decre_x, int decre_y);
void soko_exit(soko_map *map);
int draw_map_on_screen(soko_map *s_map);

#endif /* !SOKOBAN_H */
