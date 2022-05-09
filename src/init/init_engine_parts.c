/*
** EPITECH PROJECT, 2022
** init_engine_parts.c
** File description:
** functions used to intialize engine parts
*/

#include "rpg.h"

static void init_more_cartos(game_t *game)
{
    game->parts[23].texture = sfTexture_createFromFile(
    "files/car_parts/carto_type_r_pro.png", NULL);
    game->parts[23].sprite = get_sprite(game->parts[23].texture);
    sfSprite_setOrigin(game->parts[23].sprite, get_position(49, 50));
    sfSprite_setPosition(game->parts[23].sprite, get_position(1100, 850));
    game->parts[23].is_toggled = 0;
    game->parts[24].texture = sfTexture_createFromFile(
    "files/car_parts/godmode.png", NULL);
    game->parts[24].sprite = get_sprite(game->parts[24].texture);
    sfSprite_setOrigin(game->parts[24].sprite, get_position(49, 57));
    sfSprite_setPosition(game->parts[24].sprite, get_position(1400, 857));
    game->parts[24].is_toggled = 0;
}

static void init_cartos(game_t *game)
{
    game->parts[20].texture = sfTexture_createFromFile(
    "files/car_parts/speeeeed.png", NULL);
    game->parts[20].sprite = get_sprite(game->parts[20].texture);
    sfSprite_setPosition(game->parts[20].sprite, get_position(145, 250));
    sfSprite_setScale(game->parts[20].sprite, get_position(0.9, 0.9));
    game->parts[20].is_toggled = 0;
    game->parts[21].texture = sfTexture_createFromFile(
    "files/car_parts/2step.png", NULL);
    game->parts[21].sprite = get_sprite(game->parts[21].texture);
    sfSprite_setOrigin(game->parts[21].sprite, get_position(49, 59));
    sfSprite_setPosition(game->parts[21].sprite, get_position(500, 860));
    game->parts[21].is_toggled = 0;
    game->parts[22].texture = sfTexture_createFromFile(
    "files/car_parts/speeeeed.png", NULL);
    game->parts[22].sprite = get_sprite(game->parts[22].texture);
    sfSprite_setOrigin(game->parts[22].sprite, get_position(49, 50));
    sfSprite_setPosition(game->parts[22].sprite, get_position(800, 850));
    game->parts[22].is_toggled = 0;
    init_more_cartos(game);
}

void init_pistons(game_t *game)
{
    game->parts[17].texture = sfTexture_createFromFile(
    "files/car_parts/forged.png", NULL);
    game->parts[17].sprite = get_sprite(game->parts[17].texture);
    sfSprite_setOrigin(game->parts[17].sprite, get_position(30, 66));
    sfSprite_setPosition(game->parts[17].sprite, get_position(480, 856));
    game->parts[17].is_toggled = 0;
    game->parts[18].texture = sfTexture_createFromFile(
    "files/car_parts/better_forged.png", NULL);
    game->parts[18].sprite = get_sprite(game->parts[18].texture);
    sfSprite_setOrigin(game->parts[18].sprite, get_position(30, 65));
    sfSprite_setPosition(game->parts[18].sprite, get_position(930, 855));
    game->parts[18].is_toggled = 0;
    game->parts[19].texture = sfTexture_createFromFile(
    "files/car_parts/best_forged.png", NULL);
    game->parts[19].sprite = get_sprite(game->parts[19].texture);
    sfSprite_setOrigin(game->parts[19].sprite, get_position(29.5, 65));
    sfSprite_setPosition(game->parts[19].sprite, get_position(1380, 855));
    game->parts[19].is_toggled = 0;
    init_cartos(game);
}
