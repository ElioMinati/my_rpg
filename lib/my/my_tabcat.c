/*
** EPITECH PROJECT, 2022
** tabcat
** File description:
** a
*/

#include "../../includes/my.h"

char **my_tabcat(char **tab, char *tab_add)
{
    char *dest = NULL;

    if (tab == NULL) return my_str_twa(tab_add);
    for (int i = 0; tab[i] != NULL; i++) {
        dest = my_strcat(dest, "\n");
        dest = my_strcat(dest, tab[i]);
    }
    dest = my_strcat(dest, "\n");
    dest = my_strcat(dest, tab_add);
    return my_str_twa(dest);
}
