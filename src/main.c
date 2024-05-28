/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include "sokoban.h"

int main(int ac, char **av)
{
    int ret = 1;

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2) {
        my_putstr("USAGE\n    ./my_sokoban map\nDESCRIPTION\n    map file ");
        my_putstr("representing the warehouse map, containing '#' for walls,");
        my_putstr("\n        'P' for the player, 'X' for boxes and 'O' for ");
        my_putstr("storage locations.\n");
        return (0);
    } else
        ret = game(av[1]);
    return (ret);
}
