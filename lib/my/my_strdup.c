/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** a
*/

#include "../../includes/my.h"

char *my_strdup(char const *str)
{
    if (str == NULL) return NULL;
    int len = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len + 1));

    for (int i = 0; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[len] = '\0';
    return dest;
}
