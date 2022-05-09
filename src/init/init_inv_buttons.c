/*
** EPITECH PROJECT, 2022
** inivt_inv_buttons
** File description:
** .
*/

#include "rpg.h"

void init_equip(game_t *game)
{
    game->inv_buttons[2].texture = sfTexture_createFromFile(
    "files/buttons/equip.png", NULL);
    game->inv_buttons[2].sprite = get_sprite(
    game->inv_buttons[2].texture);
    sfSprite_setTextureRect(game->inv_buttons[2].sprite,
    get_rect(0, 0, 101, 41));
    sfSprite_setScale(game->inv_buttons[2].sprite,
    get_position(1, 1));
    sfSprite_setPosition(game->inv_buttons[2].sprite,
    get_position(1185, 810));
    game->inv_buttons[3].texture = sfTexture_createFromFile(
    "files/buttons/unequip.png", NULL);
    game->inv_buttons[3].sprite = get_sprite(
    game->inv_buttons[3].texture);
    sfSprite_setTextureRect(game->inv_buttons[3].sprite,
    get_rect(0, 0, 237, 79));
    sfSprite_setScale(game->inv_buttons[3].sprite,
    get_position(0.5, 0.5));
    sfSprite_setPosition(game->inv_buttons[3].sprite,
    get_position(585, 810));
}

static void init_second_arrow(game_t *game)
{
    game->inv_buttons[1].texture = sfTexture_createFromFile(
    "files/buttons/arrow.png", NULL);
    game->inv_buttons[1].sprite = get_sprite(
    game->inv_buttons[1].texture);
    sfSprite_setScale(game->inv_buttons[1].sprite,
    get_position(-0.4, 0.4));
    sfSprite_setTextureRect(game->inv_buttons[1].sprite,
    get_rect(0, 0, 324, 450));
    sfSprite_setPosition(game->inv_buttons[1].sprite,
    get_position(1830, 500));
    game->inv_buttons[1].rect = (sfIntRect){0, 0, 324, 450};
    init_equip(game);
}

void init_inv_buttons(game_t *game)
{
    game->inv_buttons = malloc(sizeof(button_t) * 4);
    game->inv_buttons[0].texture = sfTexture_createFromFile(
    "files/buttons/arrow.png", NULL);
    game->inv_buttons[0].rect = (sfIntRect){0, 0, 324, 450};
    game->inv_buttons[0].sprite = get_sprite(
    game->inv_buttons[0].texture);
    sfSprite_setTextureRect(game->inv_buttons[0].sprite,
    get_rect(0, 0, 324, 450));
    sfSprite_setScale(game->inv_buttons[0].sprite,
    get_position(0.4, 0.4));
    sfSprite_setPosition(game->inv_buttons[0].sprite,
    get_position(100, 500));
    init_second_arrow(game);
}
