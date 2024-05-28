/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include "sokoban.h"

coords_t player2(char **map_arr, coords_t pos)
{
    while (map_arr[pos.y][pos.x] != '\0') {
        if (map_arr[pos.y][pos.x] == 'P')
            return (pos);
        pos.x++;
    }
    pos.x = 0;
    pos.y = 0;
    return (pos);
}

coords_t player(char **map_arr)
{
    coords_t pos;
    coords_t play;

    play.x = 0;
    play.y = 0;
    pos.x = 0;
    pos.y = 0;
    while (map_arr[pos.y] != NULL) {
        play = player2(map_arr, pos);
        if (play.x != 0)
            return (play);
        pos.x = 0;
        pos.y++;
    }
    pos.x = 0;
    pos.y = 0;
    return (play);
}

int counter(char **map_arr, int j, int i, int *cnt)
{
    if (map_arr[j][i] == 'O') {
        *cnt++;
    }
}

int count_o(char **map_arr)
{
    int i = 0;
    int j = 0;
    int cnt = 0;

    while (map_arr[j] != NULL) {
        while (map_arr[j][i] != '\0') {
            counter(map_arr, j, i, &cnt);
            i++;
        }
        i = 0;
        j++;
    }
    return (cnt);
}

void find_o_character(char **map_arr, coords_t pos, int *i, coords_t *coor_o)
{
    if (map_arr[pos.y][pos.x] == 'O') {
        coor_o[*i] = pos;
        *i++;
    }
}
