/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** get
*/

#include "rpg.h"

sfSprite *get_sprite(sfTexture* texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfVector2f get_position(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return vector;
}

sfIntRect get_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}

sfSprite *get_sprite2(sfTexture* texture, game_t *game)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, game->main_buttons[0].rect);
    return sprite;
}
