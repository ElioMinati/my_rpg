/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** a
*/

#include "../../includes/my.h"

int calcul(const int neg, const char *dest)
{
    int nbr = 0;

    for (int i = 0; i < my_strlen(dest); i++) {
        nbr *= 10;
        nbr += dest[i] - '0';
    }
    if (neg == 1)
        nbr = nbr * -1;
    return nbr;
}

int isneg(const char *str, int i, int neg)
{
    if (str[i - 1] == '-')
        neg = 1;
    return neg;
}

int my_atoi(char const *str)
{
    if (str == NULL) return 0;
    char *dest = malloc(sizeof(char) * my_strlen(str) + 1);
    int j = 0;
    int verif = 0;
    int neg = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            verif = 1;
        if (verif == 1 && (str[i] < '0' || str[i] > '9'))
            break;
        if (verif == 1) {
            neg = isneg(str, i, neg);
            dest[j] = str[i];
            j++;
        }
    }
    dest[j] = '\0';
    return calcul(neg, dest);
}
