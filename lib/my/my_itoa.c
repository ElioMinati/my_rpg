/*
** EPITECH PROJECT, 2022
** itoa.c
** File description:
** a
*/

#include "../../includes/my.h"

char *my_itoa(int nbr)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char *) * 11);
    for (;nbr >= 10; i++) {
        str[i] = (nbr % 10) + '0';
        nbr = nbr / 10;
    }
    str[i] = nbr + '0';
    str[i + 1] = '\0';
    str = my_revstr(str);
    return str;
}
