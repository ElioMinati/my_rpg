/*
** EPITECH PROJECT, 2022
** handle_move_right.c
** File description:
** functions that handle right moving
*/

#include "rpg.h"

void handle_move_right(game_t *game, sfVector2f pos,
sfVector2f car_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) && pos.x > -1750 &&
    car_pos.x > 960 && game->movement_clock.seconds > 0.005) {
        sfSprite_setRotation(game->current_car.sprite, 0);
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        sfSprite_move(game->backgrounds[3].sprite, get_position(-20, 0));
        sfSprite_move(game->backgrounds[9].sprite, get_position(-20, 0));
        sfSprite_move(game->pnj[0].sprite, get_position(-20, 0));
        game->current_car.is_moving = 1;
        sfClock_restart(game->movement_clock.clock);
    }
    move_line_map(game, pos, car_pos);
}
