/*
** EPITECH PROJECT, 2021
** test_sokoban
** File description:
** Test sokoban
*/

#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

Test(Read_file, read_file)
{
    int fd = open_file("tests/map.txt");
    cr_assert_neq(fd, 84);

    struct stat caracnumber;
    char *buffer;
    char *compare = "##################\n"\
    "#                #\n"\
    "#  P   O         #\n"\
    "#          X     #\n"\
    "#                #\n"\
    "##################\n";

    stat("tests/map.txt", &caracnumber);
    buffer = malloc(sizeof(char) * (caracnumber.st_size + 1));
    buffer = get_buffer(buffer, caracnumber.st_size, fd);
    cr_assert_str_eq(compare, buffer);
}

Test(bad_file, read_file)
{
    int fd = open_file("map.txt");
    cr_assert_eq(fd, 84);

    struct stat caracnumber;
    char *buffer;
    char *compare = "error";

    stat("map.txt", &caracnumber);
    buffer = malloc(sizeof(char) * (caracnumber.st_size + 1));
    buffer = get_buffer(buffer, caracnumber.st_size, fd);
    cr_assert_str_eq(compare, buffer);
}

Test(get_map, read_map_from_buffer)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#  P   O         #";
    compare[3] = "#          X     #";
    compare[4] = "#                #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(move_right, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#   P  O         #";
    compare[3] = "#          X     #";
    compare[4] = "#                #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(move_right_again, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#     PO         #";
    compare[3] = "#          X     #";
    compare[4] = "#                #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(move_on_coin, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      P         #";
    compare[3] = "#          X     #";
    compare[4] = "#                #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(traverse_coin, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      OP        #";
    compare[3] = "#          X     #";
    compare[4] = "#                #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(move_box_from_above, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      O         #";
    compare[3] = "#          P     #";
    compare[4] = "#          X     #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_DOWN, map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(stuck_box, move_player, .exit_code = 1)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      O         #";
    compare[3] = "#                #";
    compare[4] = "#              PX#";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    check_stuck_boxes(map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(win, move_player, .exit_code = 0)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      XP       #";
    compare[3] = "#                #";
    compare[4] = "#                #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_UP, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_UP, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_LEFT, map);
    win_condition(map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(bad_map, read_map_from_buffer)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/too_much_coins.txt";

    init_struct(map);
    int error = check_map(map);
    cr_assert_eq(error, 84);
}

Test(good_map, read_map_from_buffer)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";

    init_struct(map);
    int error = check_map(map);
    cr_assert_eq(error, 0);
}

Test(cant_move, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#P     O         #";
    compare[3] = "#          X     #";
    compare[4] = "#                #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_LEFT, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_LEFT, map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(cant_push_box, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      O         #";
    compare[3] = "#          P     #";
    compare[4] = "#          X     #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(stuck_box_with_another_box, move_player, .exit_code = 1)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map_two.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      O         #";
    compare[3] = "#                #";
    compare[4] = "#        XXP     #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    char **carte = map->map;
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_LEFT, map);
    check_stuck_boxes(map);
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(no_win_if_only_one_box_on_coin, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map_two_coins.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      O         #";
    compare[3] = "#            PX  #";
    compare[4] = "#        X       #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    check_stuck_boxes(map);
    cr_expect_eq(0, win_condition(map));
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(cant_push_box_against_a_box, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map_two_coins.txt";
    char **compare = malloc(sizeof(char *) * 7);
    compare[0] = "##################";
    compare[1] = "#                #";
    compare[2] = "#      O P       #";
    compare[3] = "#        X    O  #";
    compare[4] = "#        X       #";
    compare[5] = "##################";
    compare[6] = NULL;

    create_map(map);
    init_struct(map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_RIGHT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_UP, map);
    move_player(KEY_LEFT, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    move_player(KEY_DOWN, map);
    check_stuck_boxes(map);
    cr_expect_eq(0, win_condition(map));
    for (int i = 0; compare[i] != NULL; i++)
        cr_expect_str_eq(map->map[i], compare[i]);
}

Test(get_p_pos, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map_two_coins.txt";

    create_map(map);
    init_struct(map);
    cr_expect_eq(map->pp_x, 2);
    cr_expect_eq(map->pp_y, 3);
}

Test(get_map_dimensions, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map_two_coins.txt";

    create_map(map);
    init_struct(map);
    cr_expect_eq(map->map_x, 19);
    cr_expect_eq(map->map_y, 6);
}

Test(get_coins_pos, move_player)
{
    soko_map *map = malloc(sizeof(soko_map));
    map->av1 = "tests/map_two_coins.txt";

    create_map(map);
    init_struct(map);
    cr_expect_eq(map->coin, 2);
    cr_expect_eq(map->coin_pos[0][0], 2);
    cr_expect_eq(map->coin_pos[0][1], 7);
    cr_expect_eq(map->coin_pos[1][0], 3);
    cr_expect_eq(map->coin_pos[1][1], 14);
}