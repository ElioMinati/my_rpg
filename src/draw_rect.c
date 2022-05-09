/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** draw_rect
*/

#include "rpg.h"

sfRectangleShape *return_rect(sfVector2f pos, sfVector2f size, int opacity,
sfRenderWindow *win)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, opacity));
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    return rect;
}

void draw_rect(sfVector2f pos, sfVector2f size, int opacity,
sfRenderWindow *win)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, opacity));
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void draw_green_border_rect(sfVector2f pos, sfVector2f size, int opacity,
sfRenderWindow *win)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, opacity));
    sfRectangleShape_setOutlineColor(rect, sfGreen);
    sfRectangleShape_setOutlineThickness(rect, 6);
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
}
