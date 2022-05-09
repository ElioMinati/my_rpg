/*
** EPITECH PROJECT, 2022
** analyse_pause
** File description:
** functions used to analyse the pause menu
*/

#include "rpg.h"

void analyse_pause_events(game_t *game, sfRenderWindow *win)
{
    if (is_button_pressed(game, game->main_buttons[13])) {
        sfSprite_setTextureRect(game->main_buttons[13].sprite,
        get_rect(168, 0, 120, 84));
        game->pause = 0;
    } else if (is_button_hovered(win, game, game->main_buttons[13])) {
        sfSprite_setTextureRect(game->main_buttons[13].sprite,
        get_rect(84, 0, 120, 84));
    } else
        sfSprite_setTextureRect(game->main_buttons[13].sprite,
        get_rect(0, 0, 120, 84));
}
