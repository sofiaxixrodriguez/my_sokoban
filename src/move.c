/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include "sokoban.h"

void move_p(char **map_arr, int key)
{
    coords_t pos = player(map_arr);

    switch (key) {
        case KEY_LEFT:
            move_left(map_arr, pos);
            return;
        case KEY_RIGHT:
            move_right(map_arr, pos);
            return;
        case KEY_UP:
            move_up(map_arr, pos);
            return;
        case KEY_DOWN:
            move_down(map_arr, pos);
            return;
        default:
            return;
    }
}

void move_up(char **map_arr, coords_t pos)
{
    if (map_arr[pos.y - 1][pos.x] == 'X' &&
        map_arr[pos.y - 2][pos.x] != 'X' &&
        map_arr[pos.y - 2][pos.x] != '#') {
        map_arr[pos.y - 1][pos.x] = ' ';
        map_arr[pos.y - 2][pos.x] = 'X';
    }
    if (map_arr[pos.y - 1][pos.x] != 'X' &&
        map_arr[pos.y - 1][pos.x] != '#') {
        map_arr[pos.y][pos.x] = ' ';
        map_arr[pos.y - 1][pos.x] = 'P';
    }
}

void move_down(char **map_arr, coords_t pos)
{
    if (map_arr[pos.y + 1][pos.x] == 'X' &&
        map_arr[pos.y + 2][pos.x] != 'X' &&
        map_arr[pos.y + 2][pos.x] != '#') {
        map_arr[pos.y + 1][pos.x] = ' ';
        map_arr[pos.y + 2][pos.x] = 'X';
    }
    if (map_arr[pos.y + 1][pos.x] != 'X' &&
        map_arr[pos.y + 1][pos.x] != '#') {
        map_arr[pos.y][pos.x] = ' ';
        map_arr[pos.y + 1][pos.x] = 'P';
    }
}

void move_left(char **map_arr, coords_t pos)
{
    if (map_arr[pos.y][pos.x - 1] == 'X' &&
        map_arr[pos.y][pos.x - 2] != 'X' &&
        map_arr[pos.y][pos.x - 2] != '#') {
        map_arr[pos.y][pos.x - 1] = ' ';
        map_arr[pos.y][pos.x - 2] = 'X';
    }
    if (map_arr[pos.y][pos.x - 1] != 'X' &&
        map_arr[pos.y][pos.x - 1] != '#') {
        map_arr[pos.y][pos.x] = ' ';
        map_arr[pos.y][pos.x - 1] = 'P';
    }
}

void move_right(char **map_arr, coords_t pos)
{
    if (map_arr[pos.y][pos.x + 1] == 'X' &&
        map_arr[pos.y][pos.x + 2] != 'X' &&
        map_arr[pos.y][pos.x + 2] != '#') {
        map_arr[pos.y][pos.x + 1] = ' ';
        map_arr[pos.y][pos.x + 2] = 'X';
    }
    if (map_arr[pos.y][pos.x + 1] != 'X' &&
        map_arr[pos.y][pos.x + 1] != '#') {
        map_arr[pos.y][pos.x] = ' ';
        map_arr[pos.y][pos.x + 1] = 'P';
    }
}
