/*
** EPITECH PROJECT, 2022
** swa
** File description:
** a
*/

#include "../../includes/my.h"

void my_show_word_array(char **tab)
{
    if (tab == NULL) return;
    for (int i = 0; tab[i] != NULL; i++)
        my_printf("%s\n", tab[i]);
}
