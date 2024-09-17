/*
** EPITECH PROJECT, 2021
** read_file
** File description:
** Read a file
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int open_file(char const *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
        return 84;
    }
    return fd;
}

char *get_buffer(char *buffer, int size, int fd)
{
    int offset = 0;
    int len = read(fd, buffer + offset, size);

    if (len <= 0)
        return ("error");
    while (len > 0) {
        offset = offset + len;
        len = read(fd, buffer + offset, size - offset);
    }
    buffer[offset] = '\0';
    return buffer;
}