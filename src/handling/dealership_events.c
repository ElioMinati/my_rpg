/*
** EPITECH PROJECT, 2022
** dealership_events.c
** File description:
** functions used to handle different dealership events
*/

#include "rpg.h"

static void handle_more_dealership_events(game_t *game,
sfVector2f pos, sfRenderWindow *win)
{
    if (is_button_pressed(game, game->dealership_buttons[1]) == 1 &&
        sfSprite_getPosition(game->cars[0].sprite).x > (-1150 *
        (game->cars->nb_cars - 2))) {
        for (int i = 0; i < game->cars->nb_cars; ++i) {
            pos = sfSprite_getPosition(game->cars[i].sprite);
            sfSprite_setPosition(game->cars[i].sprite,
            get_position(pos.x - 1150, pos.y));
        }
        sfSprite_setTextureRect(game->dealership_buttons[1].sprite,
        get_rect(450, 0, 324, 450));
    } else {
        sfSprite_setTextureRect(game->dealership_buttons[1].sprite,
        get_rect(0, 0, 324, 450));
    }
    if (game->money >= game->cars[get_dealership_car(game->cars)].price &&
    is_button_pressed(game, game->dealership_buttons[2])) {
        put_car_in_garage(game, game->cars[get_dealership_car(game->cars)]);
        game->scene = 2;
    } else if (game->cars[get_dealership_car(game->cars)].price > game->money
    && is_button_pressed(game, game->dealership_buttons[2])) {
        sfClock_restart(game->error_clock.clock);
        game->error_clock.error = 1;
    }
    if (game->error_clock.error == 1)
        display_error_message(get_position(810, 850),
        "Not enough money", game, win);
}

void handle_dealership_events(game_t *game, sfRenderWindow *win)
{
    sfVector2f pos = {0, 0};

    if (is_button_pressed(game, game->dealership_buttons[0]) == 1 &&
        sfSprite_getPosition(game->cars[0].sprite).x < 500) {
        for (int i = 0; i < game->cars->nb_cars; ++i) {
            pos = sfSprite_getPosition(game->cars[i].sprite);
            sfSprite_setPosition(game->cars[i].sprite,
            get_position(pos.x + 1150, pos.y));
        }
        sfSprite_setTextureRect(game->dealership_buttons[0].sprite,
        get_rect(450, 0, 324, 450));
    } else {
        sfSprite_setTextureRect(game->dealership_buttons[0].sprite,
        get_rect(0, 0, 324, 450));
    }
    handle_more_dealership_events(game, pos, win);
}

int get_dealership_car(car_t *cars)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; i < cars->nb_cars; ++i) {
        pos = sfSprite_getPosition(cars[i].sprite);
        if (pos.x  < 1600 && pos.x > 500)
            return i;
    }
    return -1;
}

void set_dealership_cars(game_t *game)
{
    int x = -200;

    for (int i = 0; i < game->cars->nb_cars; ++i) {
        sfSprite_setPosition(game->cars[i].sprite,
        get_position(x, 700));
        sfSprite_setScale(game->cars[i].sprite,
        get_position(1.6, 1.6));
        x += 1150;
    }
}