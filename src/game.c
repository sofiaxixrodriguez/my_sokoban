/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include "sokoban.h"

char **map_to_arr(char const *map, int h)
{
    char **map_arr = malloc(sizeof(char *) * (h + 1));
    int i = 0;
    int j = 0;

    if (map_arr == NULL)
        return (NULL);
    while (i < h) {
        map_arr[i] = my_strndup(map + j, map_width(map + j) + 1);
        j += map_width(map + j) + 1;
        if (map_arr[i] == NULL)
            return (NULL);
        i++;
    }
    map_arr[h] = NULL;
    return (map_arr);
}

void free_map(char *map, char **map_arr, coords_t *coor_o)
{
    int i = 0;

    while (map_arr[i] != NULL) {
        free(map_arr[i]);
        i++;
    }
    free(map);
    free(coor_o);
}

coords_t dimesions(char *map)
{
    coords_t dim;

    dim.y = map_height(map);
    dim.x = max_width(map, dim.y);
    return (dim);
}

int game(char *src)
{
    char *map = read_map(src);
    coords_t dim = dimesions(map);
    char **map_arr = map_to_arr(map, dim.y);
    coords_t *coor_o;
    int restart = -1;

    if (map == NULL || map_arr == NULL)
        return (84);
    coor_o = find_o(map_arr);
    check_lose(map_arr, dim);
    restart = start_disp(map_arr, coor_o, dim, restart);
    free_map(map, map_arr, coor_o);
    if (restart == 2)
        restart = game(src);
    return (restart);
}
