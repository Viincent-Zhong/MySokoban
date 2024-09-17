/*
** EPITECH PROJECT, 2021
** get_map
** File description:
** Get the map from a map file
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "sokoban.h"

void get_max_x(soko_map *map, int k)
{
    if (map->map_x < k)
        map->map_x = k;
}

int get_arr_size(char *buffer, soko_map *map)
{
    int size = 0;

    for (int i = 0, k = 0; buffer[i] != '\0'; i++, k++) {
        if (buffer[i] == '\n') {
            size++;
            get_max_x(map, k);
            k = 0;
        }
    }
    map->map_y = size;
    return size;
}

char **change_to_array(char *buffer, soko_map *map)
{
    char **arr = malloc(sizeof(char *) * (get_arr_size(buffer, map) + 2));
    int len = map->map_x;
    int j = 0;

    check_malloc(arr, map);
    for (int i = 0, x = 0; buffer[i] != '\0'; i++, j++) {
        arr[j] = malloc(sizeof(char) * (len + 1));
        check_malloc(arr[j], map);
        for (x = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++, x++)
            arr[j][x] = buffer[i];
        arr[j][x] = '\0';
    }
    arr[j] = NULL;
    return arr;
}

void create_map(soko_map *map)
{
    int fd = open_file(map->av1);
    struct stat caracnumber;
    char *buffer;
    char **arr;

    stat(map->av1, &caracnumber);
    buffer = malloc(sizeof(char) * (caracnumber.st_size + 1));
    check_malloc(buffer, map);
    buffer = get_buffer(buffer, caracnumber.st_size, fd);
    arr = change_to_array(buffer, map);
    map->map = arr;
}

int check_map(soko_map *map)
{
    if (map->coin > map->boxes)
        return 84;
    return 0;
}