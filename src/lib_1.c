/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#include "sokoban.h"

void my_errorchar(char c)
{
    write(2, &c, 1);
}

int my_errorstr(char const *str)
{
    int i = 0;
    int a;

    while (str[i] != '\0') {
        my_errorchar(str[i]);
        i++;
    }
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    int a;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    a = my_strlen(str);
    return (a);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
