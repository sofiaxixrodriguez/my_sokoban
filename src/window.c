/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include "sokoban.h"

void key_event(char **map_arr, int key, int *restart)
{
    if (key == ' ')
        *restart = 2;
    if (key == 'x')
        *restart = 3;
    if (key == KEY_UP || key == KEY_DOWN ||
        key == KEY_LEFT || key == KEY_RIGHT)
        move_p(map_arr, key);
}

void disp_game(char **map_arr, coords_t *coor_o, coords_t dim, int *restart)
{
    int i = 0;

    clear();
    check_o(map_arr, coor_o);
    if (check_win(map_arr, coor_o))
        *restart = 0;
    if (check_lose(map_arr, dim))
        *restart = 1;
    while (i < dim.y) {
        mvprintw(LINES / 2 - dim.y / 2 + i, COLS / 2 - dim.x / 2, map_arr[i]);
        i++;
    }
    if (*restart != 0 && *restart != 1)
        key_event(map_arr, getch(), restart);
    i = 0;
    refresh();
}

int display(char **map_arr, coords_t *coor_o, coords_t dim, int restart)
{
    char *str_enlarge;

    while (restart < 0 || restart > 3) {
        if (LINES < dim.y || COLS < dim.x) {
            str_enlarge = "PLS ENLARGE TERMINAL";
            clear();
            mvprintw(LINES / 2, COLS / 2 - my_strlen(str_enlarge) / 2,
            str_enlarge);
            refresh();
        } else
            disp_game(map_arr, coor_o, dim, &restart);
    }
    return (restart);
}

int start_disp(char **map_arr, coords_t *coor_o, coords_t dim, int restart)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    restart = display(map_arr, coor_o, dim, restart);
    endwin();
    return (restart);
}
