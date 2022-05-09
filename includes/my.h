/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

#ifndef MY_H_
    #define MY_H_

void my_putchar(const char c);
int my_putstr(char const *str);
int my_putstr_2(char const *str);
void my_printf(const char *format, ...);
void my_put_nbr(int nb);
void my_put_nbr_u(int nb);
int my_strlen(char const *str);
char *my_convert_base(const int base, int num);
char *my_revstr(char *str);
char *my_itoa(int nbr);
int my_atoi(char const *str);
void my_swap(int *a, int *b);
char *my_strcat(char *dest, char *src);
char *my_strdup(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_twa(char *str);
void my_show_word_array(char **tab);
char **my_tabcat(char **tab, char *tab_add);

#endif /* MY_H_ */
