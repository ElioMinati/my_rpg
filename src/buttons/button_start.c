/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** button_start
*/

#include "rpg.h"

void manage_start_button(sfRenderWindow *window, game_t *game)
{
    if (game->event.type == sfEvtMouseButtonReleased) {
        if (game->event.mouseButton.x > 754 &&
            game->event.mouseButton.x < 1097 &&
            game->event.mouseButton.y > 816 &&
            game->event.mouseButton.y < 983) {
            game->main_buttons[0].rect = (sfIntRect){0, 0, 157, 77};
            sfSprite_setTextureRect(game->main_buttons[0].sprite,
            game->main_buttons[0].rect);
            game->scene = 1; game->event.type = sfEvtMouseButtonReleased;
            }
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (game->event.mouseButton.x > 754 && game->event.mouseButton.x <
            1097 && game->event.mouseButton.y > 816 &&
            game->event.mouseButton.y < 983) {
            game->main_buttons[0].rect = (sfIntRect){0, 77, 157, 77};
            sfSprite_setTextureRect(game->main_buttons[0].sprite,
            game->main_buttons[0].rect);
            }
    } manage_start_buttonb(window, game);
}

void manage_end_button(sfRenderWindow *window, game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (game->event.mouseButton.x > 804 &&
            game->event.mouseButton.x < 887 &&
            game->event.mouseButton.y > 143 &&
            game->event.mouseButton.y < 151) {
            game->scene = 2;
            game->event.type = sfEvtMouseButtonReleased;
            }
    }
}

void manage_quit_button(sfRenderWindow *window, game_t *game)
{
    if (game->event.type == sfEvtMouseButtonReleased) {
        if (game->event.mouseButton.x > 15 &&
            game->event.mouseButton.x < 214 &&
            game->event.mouseButton.y > 942 &&
            game->event.mouseButton.y < 1019) {
            sfRenderWindow_close(window);
            }
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (game->event.mouseButton.x > 15 &&
            game->event.mouseButton.x < 214 &&
            game->event.mouseButton.y > 942 &&
            game->event.mouseButton.y < 1019) {
            game->main_buttons[2].rect = get_rect(13, 0, 34, 34);
            sfSprite_setTextureRect(game->main_buttons[2].sprite,
            game->main_buttons[2].rect);
            }
    }
    manage_quit_buttonb(window, game);
}