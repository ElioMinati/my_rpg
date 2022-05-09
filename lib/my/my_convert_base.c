/*
** EPITECH PROJECT, 2022
** base converter
** File description:
** a
*/

#include "../../includes/my.h"

char *my_convert_base(int base, int num)
{
    char *dest = malloc(sizeof(char *) * 11);
    int temp = 0;
    int i = 0;
    int neg = 0;

    if (num < 0) {
        num *= -1;
        neg = 1;
    }
    for (; num != 0; i++) {
        temp = num % base;
        num /= base;
        if (temp >= 0 && temp <= 9)
            dest[i] = temp + '0';
        else
            dest[i] = temp - 10 + 'A';
    }
    (neg == 1) ? (dest[i] = '-', dest[i + 1] = '\0') : (dest[i] = '\0');
    return my_revstr(dest);
}
