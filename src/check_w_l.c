/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** check win/lose
*/

#include "sokoban.h"

void check_o(char **map_arr, coords_t *coor_o)
{
    coords_t pos = coor_o[0];
    int i = 0;

    while (pos.x != 0 && pos.y != 0) {
        if (map_arr[pos.y][pos.x] == ' ')
            map_arr[pos.y][pos.x] = 'O';
        i++;
        pos = coor_o[i];
    }
}

int check_win(char **map_arr, coords_t *coor_o)
{
    coords_t pos = coor_o[0];
    int i = 0;
    int counter = 0;

    while (pos.x != 0 && pos.y != 0) {
        if (map_arr[pos.y][pos.x] == 'X')
            counter++;
        i++;
        pos = coor_o[i];
    }
    if (counter == i)
        return (1);
    return (0);
}

int check_box_corner(char **map, coords_t pos)
{
    int corner = 0;

    if (map[pos.y - 1][pos.x] == '#' || map[pos.y - 1][pos.x] == 'X') {
        corner++;
    } else if (map[pos.y + 1][pos.x] == '#' || map[pos.y + 1][pos.x] == 'X') {
        corner++;
    }
    if (map[pos.y][pos.x - 1] == '#' || map[pos.y][pos.x - 1] == 'X') {
        corner++;
    } else if (map[pos.y][pos.x + 1] == '#' || map[pos.y][pos.x + 1] == 'X') {
        corner++;
    }
    if (corner > 1)
        return (1);
    else
        return (0);
}

int check_lose2(int *blocked_box, int *box_nb, coords_t *pos, char **map_arr)
{
    while (map_arr[(*pos).y][(*pos).x] != '\n') {
        if (map_arr[(*pos).y][(*pos).x] == 'X') {
            *box_nb = *box_nb + 1;
            *blocked_box += check_box_corner(map_arr, (*pos));
        }
        (*pos).x++;
    }
}

int check_lose(char **map_arr, coords_t dim)
{
    coords_t pos;
    int blocked_box = 0;
    int box_nb = 0;

    pos.x = 0;
    pos.y = 0;
    while (pos.y < dim.y) {
        check_lose2(&blocked_box, &box_nb, &pos, map_arr);
        pos.y++;
        pos.x = 0;
    }
    if (box_nb == blocked_box)
        return (1);
    return (0);
}
