/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** window_basics
*/

#include "rpg.h"

sfRenderWindow *create_renderwindow(unsigned int x, unsigned int y
                                            , unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, title, sfDefaultStyle, NULL));
}

void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}
