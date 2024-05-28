/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

int map_height(char const *map)
{
    int i = 0;
    int h = 0;

    while (map[i] != '\0') {
        if (map[i] == '\n')
            h++;
        i++;
    }
    return (h);
}

int map_width(char const *map)
{
    int i = 0;

    while (map[i] != '\n') {
        i++;
    }
    return (i);
}

int max_width(char const *map, int height)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    int width = 0;

    while (i < height && map[j] != '\0') {
        if (map[j] == '\n') {
            tmp = 0;
            i++;
        }
        if (tmp > width)
            width = tmp;
        tmp++;
        j++;
    }
    return (width);
}

int get_map_size(char const *path)
{
    struct stat file;

    if (stat(path, &file) < 0)
        return (-1);
    return (file.st_size);
}

char *read_map(char const *filepath)
{
    int size = get_map_size(filepath);
    char *buffer = malloc(sizeof(char) * size);
    int fd = open(filepath, O_RDONLY);
    int i = 0;

    if (fd == -1 || size == -1)
        return (NULL);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    while (buffer[i] != '\0') {
        if (buffer[i] != '\n' && buffer[i] != '#' && buffer[i] != 'X' &&
            buffer[i] != 'O' && buffer[i] != 'P' && buffer[i] != ' ') {
            my_putstr("ERROR: invalid map\n");
            return (NULL);
            }
        i++;
    }
    return (buffer);
}
