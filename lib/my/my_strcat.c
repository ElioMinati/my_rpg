/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** a
*/

#include "../../includes/my.h"

char *my_strcat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    char *tmp_dest = my_strdup(dest);
    int j = 0;

    if (dest == NULL && src == NULL) return NULL;
    if (dest == NULL) return src;
    if (src == NULL) return dest;
    dest = malloc(sizeof(char) * (my_strlen(tmp_dest) + my_strlen(src) + 1));
    for (int i = 0; tmp_dest[i] != '\0'; i++)
        dest[i] = tmp_dest[i];
    for (;src[j] != '\0'; dest_len++, j++)
        dest[dest_len] = src[j];
    dest[dest_len] = '\0';
    return dest;
}
