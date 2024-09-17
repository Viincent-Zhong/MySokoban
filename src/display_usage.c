/*
** EPITECH PROJECT, 2021
** display_usage
** File description:
** Display usage with -h
*/

#include "my.h"
#include "sokoban.h"
#include <stdlib.h>
#include <unistd.h>

void disp_usage(char **av, int ac)
{
    if (ac != 2) {
        write(2, "Need map argument\n", 19);
        exit(84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2) {
        my_printf("USAGE\n     ./my_sokoban map\n");
        my_printf("DESCRIPTION\n     map  file representing the warehouse map");
        my_printf(", containing '#' for walls,\n         'P' for the player");
        my_printf(", 'X' for boxes and 'O' for storage locations.\n");
        exit(0);
    }
}