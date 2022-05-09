/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** a
*/

#include "../../includes/my.h"

int my_putstr(char const *str)
{
    if (str == NULL) return 0;
    write(1, str, my_strlen(str));
    return 0;
}
