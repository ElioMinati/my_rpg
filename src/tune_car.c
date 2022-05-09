/*
** EPITECH PROJECT, 2022
** tune_car.c
** File description:
** functions used to tune or detune the car in garage
*/

#include "rpg.h"

void tune(game_t *game, item_t item)
{
    game->current_car.horse_power *= item.gain;
    game->current_car.max_speed *= item.gain;
    game->garage[game->current_car.garage_pos].horse_power *= item.gain;
    game->garage[game->current_car.garage_pos].max_speed *=
    (1 + (1 - item.gain) / 4);
    if (item.type == TURBO) {
        game->current_car.turbo = 1;
        game->garage[game->current_car.garage_pos].turbo = 1;
    }
}

void detune(game_t *game, item_t item)
{
    game->current_car.horse_power /= item.gain;
    game->current_car.max_speed /= item.gain;
    game->garage[game->current_car.garage_pos].horse_power /= item.gain;
    game->garage[game->current_car.garage_pos].max_speed /=
    (1 + (1 - item.gain) / 4);
    if (item.type == TURBO) {
        game->current_car.turbo = 0;
        game->garage[game->current_car.garage_pos].turbo = 0;
    }
}
