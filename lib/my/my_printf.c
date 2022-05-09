/*
** EPITECH PROJECT, 2022
** sum_numbers.c
** File description:
** a
*/

#include "../../includes/my.h"

int display_base(va_list list, const char *format, int i)
{
    int base = 0;

    if (format[i] == '/') {
        i++;
        for (; format[i] >= '0' && format[i] <= '9'; i++) {
            (base != 0) ? (base *= 10) : (0);
            base += (format[i] - '0');
        }
        if (base == 16)
            my_putstr("0x");
        if (base == 8)
            my_putstr("0");
        my_putstr(my_convert_base(base, va_arg(list, int)));
        i--;
    }
    return i;
}

void display_opt(va_list list, const char *format, int i)
{
    if (format[i] == '%') my_putchar('%');
    if (format[i] == 'i') my_put_nbr(va_arg(list, int));
    if (format[i] == 's') my_putstr(va_arg(list, char *));
    if (format[i] == 'u') my_put_nbr_u(va_arg(list, int));
    if (format[i] == 'c') my_putchar(va_arg(list, int));
    if (format[i] == 'e') my_putstr_2(va_arg(list, char *));
}

void my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            display_opt(list, format, i);
            i = display_base(list, format, i);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(list);
}
