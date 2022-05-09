/*
** EPITECH PROJECT, 2022
** analyse_part_shop_events.c
** File description:
** functions used to analyse part shop events
*/

#include "rpg.h"

void move_purchase_rect(game_t *game)
{
    if (game->parts->selected != -1 && is_button_pressed(game,
    game->dealership_buttons[2])) {
        sfSprite_setTextureRect(game->dealership_buttons[2].sprite,
        get_rect(80, 0, 200, 80));
        check_selected(game);
    } else
        sfSprite_setTextureRect(game->dealership_buttons[2].sprite,
        get_rect(0, 0, 200, 80));
    if (game->parts->selected != -1 && is_button_hovered(game->win,
    game, game->dealership_buttons[2]))
        draw_rect(sfSprite_getPosition(game->dealership_buttons[2].sprite),
        get_position(200, 70), 40, game->win);
    if (game->error_clock.error == 1)
        display_error_message(get_position(80, 820),
        "Not enough money", game, game->win);
    if (game->error_clock.error == 2)
        display_error_message(get_position(80, 820),
        "Not enough xp", game, game->win);
}

void analyse_radiator_events(sfRenderWindow *window, game_t *game)
{
    if (is_button_hovered(window, game, game->parts[10]))
        sfSprite_setScale(game->parts[10].sprite, get_position(2, 2));
    else
        sfSprite_setScale(game->parts[10].sprite, get_position(1.8, 1.8));
    if (is_button_pressed(game, game->parts[10])) {
        if (game->parts[10].is_toggled == 0) {
            game->parts[10].is_toggled = 1;
            game->parts[4].is_toggled = 0;
            game->parts[5].is_toggled = 0;
            game->parts[16].is_toggled = 0;
            game->parts[20].is_toggled = 0;
            game->parts->selected = -1;
        } else {
            game->parts[10].is_toggled = 0;
            game->parts->selected = -1;
        }
    }
    analyse_piston_events(window, game);
}

void analyse_air_filter_events(sfRenderWindow *window, game_t *game)
{
    if (is_button_hovered(window, game, game->parts[5]))
        sfSprite_setScale(game->parts[5].sprite, get_position(1.8, 1.8));
    else
        sfSprite_setScale(game->parts[5].sprite, get_position(1.6, 1.6));
    if (is_button_pressed(game, game->parts[5])) {
        if (game->parts[5].is_toggled == 0) {
            game->parts[5].is_toggled = 1;
            game->parts[4].is_toggled = 0;
            game->parts[10].is_toggled = 0;
            game->parts[16].is_toggled = 0;
            game->parts[20].is_toggled = 0;
            game->parts->selected = -1;
        } else {
            game->parts[5].is_toggled = 0;
            game->parts->selected = -1;
        }
    }
    analyse_radiator_events(window, game);
}

void analyse_shop_events(sfRenderWindow *window, game_t *game)
{
    if (is_button_hovered(window, game, game->parts[4]))
        sfSprite_setScale(game->parts[4].sprite, get_position(1.4, 1.4));
    else
        sfSprite_setScale(game->parts[4].sprite, get_position(1.2, 1.2));
    if (is_button_pressed(game, game->parts[4])) {
        if (game->parts[4].is_toggled == 0) {
            game->parts[4].is_toggled = 1;
            game->parts[5].is_toggled = 0;
            game->parts[10].is_toggled = 0;
            game->parts[16].is_toggled = 0;
            game->parts[20].is_toggled = 0;
            game->parts->selected = -1;
        } else {
            game->parts[4].is_toggled = 0;
            game->parts->selected = -1;
        }
    }
    analyse_air_filter_events(window, game);
}
