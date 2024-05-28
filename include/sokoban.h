/*
** EPITECH PROJECT, 2019
** duck_hunth
** File description:
** header for duck hunt
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SOKO_H_
    #define SOKO_H_

typedef struct coords {
    int x;
    int y;
} coords_t;

void move_p(char **map_arr, int key);
void move_up(char **map_arr, coords_t pos);
void move_down(char **map_arr, coords_t pos);
void move_left(char **map_arr, coords_t pos);
void move_right(char **map_arr, coords_t pos);
coords_t get_dim(char *map);
int get_map_size(char const *path);
int count_o(char **map_arr);
coords_t *find_o(char **map_arr);
int map_width(char const *map);
coords_t player(char **map_arr);
void key_event(char **map_arr, int key, int *play);
int max_width(char const *map, int height);
int map_height(char const *map);
int check_win(char **map_arr, coords_t *o_arr);
void check_o(char **map_arr, coords_t *o_arr);
int check_lose(char **map_arr, coords_t dim);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strndup(char const *src, int n);
coords_t player2(char **map_arr, coords_t pos);
void find_o_character(char **map_arr, coords_t pos, int *i, coords_t *coor_o);
char *read_map(char const *filepath);
int start_disp(char **map_arr, coords_t *o_arr, coords_t dim, int restart);
int game(char *src);
char **map_to_lines(char const *map, int height);

#endif
