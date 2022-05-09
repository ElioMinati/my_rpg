/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** manage_return
*/

#include "rpg.h"

void check_return(sfRenderWindow *window, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (pos.x > 1815 && pos.x < 1910 && pos.y > 15 &&
        pos.y < 80) {
        sfSprite_setPosition(game->main_buttons[10].sprite,
        get_position(1810, 10));
        sfSprite_setScale(game->main_buttons[10].sprite,
        get_position(2.2, 2.2));
    } else {
        sfSprite_setPosition(game->main_buttons[10].sprite,
        get_position(1815, 10));
        sfSprite_setScale(game->main_buttons[10].sprite,
        get_position(2, 2));
    }
}

void do_hoover_return(sfRenderWindow *window, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (pos.x > 1815 && pos.x < 1910 && pos.y > 15 &&
        pos.y < 80) {
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->main_buttons[10].rect = (sfIntRect){0, 0, 48, 35};
            sfSprite_setScale(game->main_buttons[10].sprite,
            get_position(2.1, 2.1));
        } else if (game->event.type == sfEvtMouseButtonReleased) {
            game->main_buttons[10].rect = (sfIntRect){0, 48, 48, 35};
            sfSprite_setScale(game->main_buttons[10].sprite,
            get_position(2.1, 2.1));
        }
    }
    sfSprite_setTextureRect(game->main_buttons[10].sprite,
    game->main_buttons[10].rect);
}

void manage_return(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->main_buttons[10].sprite, NULL);
    check_return(window, game);
    if (game->event.mouseButton.x > 1815 && game->event.mouseButton.x < 1910
        && game->event.mouseButton.y > 15 && game->event.mouseButton.y < 80
        && game->event.type == sfEvtMouseButtonPressed) {
        do_hoover_return(window, game);
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        game->inventory.status = 0;
        game->scene = 2;
        game->event.type = sfEvtMouseButtonReleased;
        game->inventory.rect = (sfIntRect){0, 0, 50, 48};
        sfSprite_setTextureRect(game->inventory.button_sprite,
        game->inventory.rect);
    }
}
