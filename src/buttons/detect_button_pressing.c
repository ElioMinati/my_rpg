/*
** EPITECH PROJECT, 2022
** detect_button_pressing.c
** File description:
** functions used to detect button pressing
*/

#include "rpg.h"

static int detect_inverse_button_pressed(game_t *game, button_t button)
{
    sfVector2f pos = sfSprite_getPosition(button.sprite);
    sfIntRect rect = sfSprite_getTextureRect(button.sprite);
    sfVector2f scale = sfSprite_getScale(button.sprite);
    sfVector2f origin = sfSprite_getOrigin(button.sprite);

    if (game->event.mouseButton.x < (pos.x - (origin.x * scale.x)) &&
    game->event.mouseButton.x > (pos.x - (origin.x * scale.x) +
    rect.width * scale.x) && game->event.mouseButton.y >
    (pos.y - (origin.y * scale.y)) &&
    game->event.mouseButton.y < (pos.y - (origin.y * scale.y) +
    rect.height * scale.y) &&
    game->event.type == sfEvtMouseButtonPressed) {
        game->event.type = sfEvtMouseButtonReleased;
        return 1;
    }
    return 0;
}

int is_button_pressed(game_t *game, button_t button)
{
    sfVector2f pos = sfSprite_getPosition(button.sprite);
    sfIntRect rect = sfSprite_getTextureRect(button.sprite);
    sfVector2f scale = sfSprite_getScale(button.sprite);
    sfVector2f origin = sfSprite_getOrigin(button.sprite);

    if (scale.x < 0) {
        return detect_inverse_button_pressed(game, button);
    } else {
        if (game->event.mouseButton.x > (pos.x - (origin.x * scale.x)) &&
        game->event.mouseButton.x < (pos.x - (origin.x * scale.x) +
        rect.width * scale.x) && game->event.mouseButton.y >
        (pos.y - (origin.y * scale.y)) &&
        game->event.mouseButton.y < (pos.y - (origin.y * scale.y) +
        rect.height * scale.y) &&
        game->event.type == sfEvtMouseButtonPressed) {
            game->event.type = sfEvtMouseButtonReleased;
            return 1;
        }
    }
    return 0;
}

static int detect_inverse_button_hovered(sfRenderWindow *win,
game_t *game, button_t button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = sfSprite_getPosition(button.sprite);
    sfIntRect rect = sfSprite_getTextureRect(button.sprite);
    sfVector2f scale = sfSprite_getScale(button.sprite);
    sfVector2f origin = sfSprite_getOrigin(button.sprite);

    if (mouse.x < mouse.x &&
    mouse.x > (pos.x + (origin.x * scale.x) +
    rect.width * scale.x) && mouse.y > pos.y &&
    mouse.y < (pos.y + (origin.x * scale.x) +
    rect.height * scale.y)) {
        return 1;
    }
    return 0;
}

int is_button_hovered(sfRenderWindow *win, game_t *game, button_t button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = sfSprite_getPosition(button.sprite);
    sfIntRect rect = sfSprite_getTextureRect(button.sprite);
    sfVector2f scale = sfSprite_getScale(button.sprite);
    sfVector2f origin = sfSprite_getOrigin(button.sprite);

    if (scale.x < 0) {
        return detect_inverse_button_hovered(win, game, button);
    } else {
        if (mouse.x > pos.x &&
        mouse.x < (pos.x + (origin.x * scale.x)
        + rect.width * scale.x) && mouse.y > pos.y &&
        mouse.y < (pos.y + (origin.x * scale.x)
        + rect.height * scale.y)) {
            return 1;
        }
    }
    return 0;
}
