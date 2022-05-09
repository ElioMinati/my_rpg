/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** events_handeling
*/

#include "rpg.h"

static void move_more_car(game_t *game, sfVector2f car_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && car_pos.y < 920
    && game->movement_clock.seconds > 0.005) {
        sfSprite_setScale(game->current_car.sprite, get_position(-0.7, 0.7));
        sfSprite_setRotation(game->current_car.sprite, 270);
        sfSprite_move(game->current_car.sprite, get_position(0, 20));
        game->current_car.is_moving = 1;
        sfClock_restart(game->movement_clock.clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && car_pos.y > 160
    && game->movement_clock.seconds > 0.005) {
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        sfSprite_setRotation(game->current_car.sprite, 270);
        sfSprite_move(game->current_car.sprite, get_position(0, -20));
        game->current_car.is_moving = 1;
        sfClock_restart(game->movement_clock.clock);
    }
}

static void move_map_car(game_t *game, sfVector2f car_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && car_pos.x > 160
    && game->movement_clock.seconds > 0.005) {
        sfSprite_setRotation(game->current_car.sprite, 0);
        sfSprite_setScale(game->current_car.sprite, get_position(-0.7, 0.7));
        sfSprite_move(game->current_car.sprite, get_position(-20, 0));
        game->current_car.is_moving = 1;
        sfClock_restart(game->movement_clock.clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && car_pos.x < 1780
    && game->movement_clock.seconds > 0.005) {
        sfSprite_setRotation(game->current_car.sprite, 0);
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        sfSprite_move(game->current_car.sprite, get_position(20, 0));
        game->current_car.is_moving = 1;
        sfClock_restart(game->movement_clock.clock);
    }
    move_more_car(game, car_pos);
}

void move_line_map(game_t *game, sfVector2f pos, sfVector2f car_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && pos.y > -1874 &&
    car_pos.y > 540 && game->movement_clock.seconds > 0.005) {
        sfSprite_setScale(game->current_car.sprite, get_position(-0.7, 0.7));
        sfSprite_setRotation(game->current_car.sprite, 270);
        sfSprite_move(game->backgrounds[3].sprite, get_position(0, -20));
        sfSprite_move(game->backgrounds[9].sprite, get_position(0, -20));
        sfSprite_move(game->pnj[0].sprite, get_position(0, -20));
        game->current_car.is_moving = 1;
        sfClock_restart(game->movement_clock.clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && pos.y < 0 && car_pos.y < 540
    && game->movement_clock.seconds > 0.005) {
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        sfSprite_setRotation(game->current_car.sprite, 270);
        sfSprite_move(game->backgrounds[3].sprite, get_position(0, 20));
        sfSprite_move(game->backgrounds[9].sprite, get_position(0, 20));
        sfSprite_move(game->pnj[0].sprite, get_position(0, 20));
        game->current_car.is_moving = 1;
        sfClock_restart(game->movement_clock.clock);
    }
}

static void move_car(game_t *game)
{
    int has_moved = 0;
    sfVector2f pos = sfSprite_getPosition(game->backgrounds[3].sprite);
    sfVector2f car_pos = sfSprite_getPosition(game->current_car.sprite);

    game->movement_clock.seconds = sfTime_asSeconds(
    sfClock_getElapsedTime(game->movement_clock.clock));
    if (colision_is_touch(game, pos, car_pos) == 1) return;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && pos.x < 0 && car_pos.x < 960
    && game->movement_clock.seconds > 0.005) {
        sfSprite_setRotation(game->current_car.sprite, 0);
        sfSprite_setScale(game->current_car.sprite, get_position(-0.7, 0.7));
        sfSprite_move(game->backgrounds[3].sprite, get_position(20, 0));
        sfSprite_move(game->backgrounds[9].sprite, get_position(20, 0));
        sfSprite_move(game->pnj[0].sprite, get_position(20, 0));
        game->current_car.is_moving = 1;
        sfClock_restart(game->movement_clock.clock);
    }
    handle_move_right(game, pos, car_pos);
    if (game->current_car.is_moving == 1) return;
    move_map_car(game, car_pos);
}

void inputhandler(sfRenderWindow *window, game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->scene == 0)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyQ) && game->scene == 0)
        sfRenderWindow_close(window);
    if (game->scene == 2)
        move_car(game);
    if (sfKeyboard_isKeyPressed(sfKeyS) && game->scene == 0)
        game->scene = 1;
    if (sfKeyboard_isKeyPressed(sfKeyBack) && game->scene == 1)
        game->scene = 0;
    if (sfKeyboard_isKeyPressed(sfKeyD) && game->scene == 0)
        game->scene = 6;
}
