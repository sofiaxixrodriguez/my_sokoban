/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include <stdlib.h>
#include "sokoban.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(src);

    while (n > i) {
        dest[i] = src[i];
        i++;
        if (i == n && len < n)
            dest[i] = '\0';
    }
    return (dest);
}

char *my_strndup(char const *src, int n)
{
    char *str = malloc(sizeof(char) * (n + 1));

    if (str == NULL)
        return (NULL);
    my_strncpy(str, src, n);
    str[n] = '\0';
    return (str);
}

coords_t *find_o(char **map_arr)
{
    int i = 0;
    coords_t pos;
    coords_t *coor_o = malloc(sizeof(coords_t) * (count_o(map_arr) + 1));

    pos.x = 0;
    pos.y = 0;
    while (map_arr[pos.y] != NULL) {
        while (map_arr[pos.y][pos.x] != '\n') {
            find_o_character(map_arr, pos, &i, coor_o);
            pos.x++;
        }
        pos.x = 0;
        pos.y++;
    }
    return (coor_o);
}
