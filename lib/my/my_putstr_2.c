/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** a
*/

#include "../../includes/my.h"

int my_putstr_2(char const *str)
{
    if (str == NULL) return 0;
    write(2, str, my_strlen(str));
    return 0;
}
