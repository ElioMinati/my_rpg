/*
** EPITECH PROJECT, 2022
** move_texture_rect.c
** File description:
** functions used to move texture rects
*/

#include "rpg.h"

void move_texture_rect(sfSprite *sprite, int offset, int max, sfClock *clock)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    if (time > 0.05) {
        rect.left += offset;
        sfClock_restart(clock);
    }
    if (rect.left >= max)
        rect.left = 0;
    sfSprite_setTextureRect(sprite, rect);
}
