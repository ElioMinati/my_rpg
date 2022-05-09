/*
** EPITECH PROJECT, 2022
** check_game_pos
** File description:
** .
*/

#include "rpg.h"

void check_binv_mouse(sfRenderWindow *window, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (pos.x < 1850 && pos.x > 1750 && pos.y < 970 &&
        pos.y > 870) {
        sfSprite_setScale(game->inventory.button_sprite,
        get_position(2.2, 2.2));
    } else {
        sfSprite_setScale(game->inventory.button_sprite,
        get_position(2, 2));
    }
}

void check_binv_pos(sfRenderWindow *window, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (pos.x < 1850 && pos.x > 1750 && pos.y < 970 &&
        pos.y > 870) {
        if (game->inventory.status == 0) {
            game->inventory.status = 1;
            game->inventory.rect = (sfIntRect){0, 50, 60, 58};
            sfSprite_setScale(game->inventory.button_sprite,
            get_position(2.1, 2.1));
        } else if (game->inventory.status == 1) {
            game->inventory.selected = -1;
            game->inventory.status = 0;
            game->inventory.rect = (sfIntRect){0, 0, 50, 48};
            sfSprite_setScale(game->inventory.button_sprite,
            get_position(2.1, 2.1));
        }
    }
    sfSprite_setTextureRect(game->inventory.button_sprite,
    game->inventory.rect);

}