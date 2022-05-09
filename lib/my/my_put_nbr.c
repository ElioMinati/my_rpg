/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** a
*/

#include "../../includes/my.h"

void my_put_nbr(int nb)
{
    int temp1;
    int temp2;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        temp1 = nb / 10;
        temp2 = nb % 10;
        if (temp1 != 0)
            my_put_nbr(temp1);
        my_putchar(temp2 + '0');
    } else {
        temp1 = nb / 10;
        temp2 = nb % 10;
        if (temp1 != 0)
            my_put_nbr(temp1);
        my_putchar(temp2 + '0');
    }
}
