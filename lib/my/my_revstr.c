/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** a
*/

#include "../../includes/my.h"

char *my_revstr(char *str)
{
    if (str == NULL) return NULL;
    int len = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len + 1));
    int j = 0;

    for (int i = len - 1; i >= 0; i--)
        dest[j++] = str[i];
    dest[len] = '\0';
    return dest;
}
