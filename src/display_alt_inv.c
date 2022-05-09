/*
** EPITECH PROJECT, 2022
** display_alt_inv
** File description:
** display alternative inventory if in garage
*/

#include "rpg.h"

void display_alt_inv(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/alt_parts_inv.png", NULL);
    sfSprite *sprite = get_sprite(texture);

    sfSprite_setPosition(sprite, get_position(300, 100));
    sfSprite_setScale(sprite, get_position(25, 25));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    display_text(get_position(455, 210), "Equiped Items", 50, win);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
