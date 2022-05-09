/*
** EPITECH PROJECT, 2022
** analyse_buttons.c
** File description:
** functions used to analyse buttons
*/

#include "rpg.h"

void detect_garage_button(sfRenderWindow *win, game_t *game)
{
    if (is_button_pressed(game, game->main_buttons[4]))
        move_garage_cars(game);
    else if (is_button_hovered(win, game, game->main_buttons[4]))
        sfSprite_setTextureRect(game->main_buttons[4].sprite,
        get_rect(142, 0, 178, 142));
    else
        sfSprite_setTextureRect(game->main_buttons[4].sprite,
        get_rect(0, 0, 178, 142));
}
