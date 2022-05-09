/*
** EPITECH PROJECT, 2022
** button_start2
** File description:
** .
*/

#include "rpg.h"

void manage_start_buttonb(sfRenderWindow *window, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (pos.x > 754 && pos.x < 1097 && pos.y > 816 && pos.y < 983) {
        sfSprite_setScale(game->main_buttons[0].sprite, get_position(2.4, 2.4));
        sfSprite_setPosition(game->main_buttons[0].sprite,
        get_position(781, 800));
    } else {
        sfSprite_setScale(game->main_buttons[0].sprite, get_position(2.2, 2.2));
        sfSprite_setPosition(game->main_buttons[0].sprite,
        get_position(795, 816));
    }
}

void manage_quit_buttonb(sfRenderWindow *window, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (pos.x > 15 && pos.x < 214 && pos.y > 942 && pos.y < 1019) {
        sfSprite_setScale(game->main_buttons[2].sprite, get_position(6.5, 6.5));
        sfSprite_setPosition(game->main_buttons[2].sprite,
        get_position(5, 935));
    } else {
        sfSprite_setScale(game->main_buttons[2].sprite, get_position(6, 6));
        sfSprite_setPosition(game->main_buttons[2].sprite,
        get_position(10, 940));
    }
}
