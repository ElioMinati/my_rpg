/*
** EPITECH PROJECT, 2022
** collision.c
** File description:
** detect collision between car and curb
*/

#include "rpg.h"

int colision_is_touch(game_t *game, sfVector2f pos, sfVector2f car_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) car_pos.x -= 50;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) car_pos.x += 50;
    if (sfKeyboard_isKeyPressed(sfKeyUp)) car_pos.y -= 50;
    if (sfKeyboard_isKeyPressed(sfKeyDown)) car_pos.y += 50;
    for (int i = 0; i != 12; i++) {
        sfVector2f rect_pos =
        sfRectangleShape_getPosition(game->colision_rect[i]);
        sfVector2f rect_size = sfRectangleShape_getSize(game->colision_rect[i]);
        if (car_pos.x >= rect_pos.x && car_pos.x <= rect_pos.x + rect_size.x &&
        car_pos.y >= rect_pos.y && car_pos.y <= rect_pos.y + rect_size.y)
            return 1;
    }
    return 0;
}

static void right_colision(game_t *game, sfRenderWindow *window,
sfVector2f pos_bg)
{
    game->colision_rect[8] = return_rect(get_position(
    pos_bg.x + 2000, pos_bg.y + 850), get_position(1130, 650), 0, window);
    game->colision_rect[9] = return_rect(get_position(
    pos_bg.x + 1220, pos_bg.y + 1750), get_position(850, 100), 0, window);
    game->colision_rect[10] = return_rect(get_position(
    pos_bg.x + 3350, pos_bg.y + 850), get_position(400, 650), 0, window);
    game->colision_rect[11] = return_rect(get_position(
    pos_bg.x + 2300, pos_bg.y + 2400), get_position(10000, 1000), 0, window);
}

void colision(game_t *game, sfRenderWindow *window)
{
    sfVector2f pos_bg = sfSprite_getPosition(game->backgrounds[3].sprite);

    game->colision_rect[0] = return_rect(get_position(
    pos_bg.x + 0, pos_bg.y + 0), get_position(950, 850), 0, window);
    game->colision_rect[1] = return_rect(get_position(
    pos_bg.x + 0, pos_bg.y + 0), get_position(1100, 700), 0, window);
    game->colision_rect[2] = return_rect(get_position(
    pos_bg.x + 0, pos_bg.y + 0), get_position(1450, 200), 0, window);
    game->colision_rect[3] = return_rect(get_position(
    pos_bg.x + 1450, pos_bg.y + 0), get_position(1160, 500), 0, window);
    game->colision_rect[4] = return_rect(get_position(
    pos_bg.x + 2830, pos_bg.y + 0), get_position(850, 600), 0, window);
    game->colision_rect[5] = return_rect(get_position(
    pos_bg.x + 0, pos_bg.y + 1750), get_position(1020, 1200), 0, window);
    game->colision_rect[6] = return_rect(get_position(
    pos_bg.x + 0, pos_bg.y + 1055), get_position(1020, 450), 0, window);
    game->colision_rect[7] = return_rect(get_position(
    pos_bg.x + 1230, pos_bg.y + 850), get_position(1900, 500), 0, window);
    right_colision(game, window, pos_bg);
}
