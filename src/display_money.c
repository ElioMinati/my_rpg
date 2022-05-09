/*
** EPITECH PROJECT, 2022
** display_money
** File description:
** functions used to display the money
*/

#include "my.h"
#include "rpg.h"

void display_money(sfRenderWindow *win, game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/dollar_money.png", NULL);
    sfSprite *sprite = get_sprite(texture);

    sfSprite_setPosition(sprite, get_position(20, 0));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    display_text(get_position(60, -2.5), my_itoa(game->money), 30, win);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
