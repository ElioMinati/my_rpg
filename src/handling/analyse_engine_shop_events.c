/*
** EPITECH PROJECT, 2022
** analyse_engine_shop_events
** File description:
** functions used to analyse engine shop events
*/

#include "rpg.h"

static void analyse_cartos_events(sfRenderWindow *window, game_t *game)
{
    if (is_button_hovered(window, game, game->parts[20]))
        sfSprite_setScale(game->parts[20].sprite, get_position(1.1, 1.1));
    else
        sfSprite_setScale(game->parts[20].sprite, get_position(0.9, 0.9));
    if (is_button_pressed(game, game->parts[20])) {
        if (game->parts[20].is_toggled == 0) {
            game->parts[16].is_toggled = 0;
            game->parts[5].is_toggled = 0;
            game->parts[4].is_toggled = 0;
            game->parts[10].is_toggled = 0;
            game->parts[20].is_toggled = 1;
            game->parts->selected = -1;
        } else {
            game->parts[20].is_toggled = 0;
            game->parts->selected = -1;
        }
    }
    move_purchase_rect(game);
}

void analyse_piston_events(sfRenderWindow *window, game_t *game)
{
    if (is_button_hovered(window, game, game->parts[16]))
        sfSprite_setScale(game->parts[16].sprite, get_position(1.3, 1.3));
    else
        sfSprite_setScale(game->parts[16].sprite, get_position(1.1, 1.1));
    if (is_button_pressed(game, game->parts[16])) {
        if (game->parts[16].is_toggled == 0) {
            game->parts[16].is_toggled = 1;
            game->parts[5].is_toggled = 0;
            game->parts[4].is_toggled = 0;
            game->parts[10].is_toggled = 0;
            game->parts[20].is_toggled = 0;
            game->parts->selected = -1;
        } else {
            game->parts[16].is_toggled = 0;
            game->parts->selected = -1;
        }
    }
    analyse_cartos_events(window, game);
}
