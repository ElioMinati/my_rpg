/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** display an error message
*/

#include "rpg.h"
#include "my.h"

void handle_car_buy(game_t *game, sfRenderWindow *win)
{
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

void display_error_message(sfVector2f pos, char *str,
game_t *game, sfRenderWindow *win)
{
    game->error_clock.seconds = sfTime_asSeconds(
    sfClock_getElapsedTime(game->error_clock.clock));
    if (game->error_clock.seconds < 2)
        display_red_text(pos, str, 30, win);
    else
        game->error_clock.error = 0;
}

void check_money(game_t *game, int selected, int price, int xp)
{
    if (game->parts->selected == selected && game->money < price) {
        sfClock_restart(game->error_clock.clock);
        game->error_clock.error = 1;
    }
    if (game->parts->selected == selected && my_atoi(game->xp) < xp) {
        sfClock_restart(game->error_clock.clock);
        game->error_clock.error = 2;
    }
}
