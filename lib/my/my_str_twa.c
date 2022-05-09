/*
** EPITECH PROJECT, 2022
** str->**
** File description:
** a
*/

#include "../../includes/my.h"

int is_separator(char ch)
{
    char *separator = ">";

    for (int i = 0; separator[i] != '\0'; i++)
        if (separator[i] == ch) return 84;
    return 0;
}

int count_words(char *str)
{
    int words = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_separator(str[i]) != 0 && is_separator(str[i + 1]) == 0
        && i != 0)
            words++;
    return words;
}

char *str_with_no_space(char *str)
{
    char *dest = my_strdup(str);

    while (is_separator(dest[0]) != 0)
        dest += 1;
    dest = my_revstr(dest);
    while (is_separator(dest[0]) != 0)
        dest += 1;
    dest = my_revstr(dest);
    return dest;
}

char **my_str_twa(char *str)
{
    if (str == NULL) return NULL;
    str = str_with_no_space(str);
    int wrds = count_words(str);
    int i = 0;
    int j = 0;
    int k = 0;
    char **dest = malloc(sizeof(char *) * (wrds + 1));
    int len = my_strlen(str);

    for (int i = 0; i != wrds; i++) dest[i] = malloc(sizeof(char) * (len + 1));
    dest[wrds] = NULL;
    for (; dest[i] != NULL; i++) {
        for (j = 0; is_separator(str[k]) == 0
        && str[k] != '\0'; j++, k++) dest[i][j] = str[k];
        dest[i][j] = '\0';
        for (;is_separator(str[k]) != 0; k++);
    }
    return dest;
}
