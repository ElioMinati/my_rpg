/*
** EPITECH PROJECT, 2022
** init_parts
** File description:
** initialise car parts
*/

#include "rpg.h"

static void init_more_radiators(game_t *game)
{
    game->parts[14].texture = sfTexture_createFromFile(
    "files/car_parts/diamond_radiator.png", NULL);
    game->parts[14].sprite = get_sprite(game->parts[14].texture);
    sfSprite_setOrigin(game->parts[14].sprite, get_position(62, 27));
    sfSprite_setPosition(game->parts[14].sprite, get_position(1112, 827));
    sfSprite_setScale(game->parts[14].sprite, get_position(1.4, 1.4));
    game->parts[14].is_toggled = 0;
    game->parts[15].texture = sfTexture_createFromFile(
    "files/car_parts/black_PR_radiator.png", NULL);
    game->parts[15].sprite = get_sprite(game->parts[15].texture);
    sfSprite_setOrigin(game->parts[15].sprite, get_position(62, 27));
    sfSprite_setPosition(game->parts[15].sprite, get_position(1462, 827));
    sfSprite_setScale(game->parts[15].sprite, get_position(1.4, 1.4));
    game->parts[15].is_toggled = 0;
    game->parts[16].texture = sfTexture_createFromFile(
    "files/car_parts/better_forged.png", NULL);
    game->parts[16].sprite = get_sprite(game->parts[16].texture);
    sfSprite_setPosition(game->parts[16].sprite, get_position(1220, 385));
    sfSprite_setScale(game->parts[16].sprite, get_position(1.1, 1.1));
    game->parts[16].is_toggled = 0; init_pistons(game);
}

static void init_radiators(game_t *game)
{
    game->parts[11].texture = sfTexture_createFromFile(
    "files/car_parts/radiator.png", NULL);
    game->parts[11].sprite = get_sprite(game->parts[11].texture);
    sfSprite_setOrigin(game->parts[11].sprite, get_position(62, 27));
    sfSprite_setPosition(game->parts[11].sprite, get_position(62, 827));
    sfSprite_setScale(game->parts[11].sprite, get_position(1.4, 1.4));
    game->parts[11].is_toggled = 0;
    game->parts[12].texture = sfTexture_createFromFile(
    "files/car_parts/radiator2.png", NULL);
    game->parts[12].sprite = get_sprite(game->parts[12].texture);
    sfSprite_setOrigin(game->parts[12].sprite, get_position(62, 27));
    sfSprite_setPosition(game->parts[12].sprite, get_position(462, 827));
    sfSprite_setScale(game->parts[12].sprite, get_position(1.4, 1.4));
    game->parts[12].is_toggled = 0;
    game->parts[13].texture = sfTexture_createFromFile(
    "files/car_parts/Pr_radiator.png", NULL);
    game->parts[13].sprite = get_sprite(game->parts[13].texture);
    sfSprite_setOrigin(game->parts[13].sprite, get_position(62, 27));
    sfSprite_setPosition(game->parts[13].sprite, get_position(812, 827));
    sfSprite_setScale(game->parts[13].sprite, get_position(1.4, 1.4));
    game->parts[13].is_toggled = 0;
    init_more_radiators(game);
}

void init_more_air_filters(game_t *game)
{
    game->parts[8].texture = sfTexture_createFromFile(
    "files/car_parts/weird_air_filter.png", NULL);
    game->parts[8].sprite = get_sprite(game->parts[8].texture);
    sfSprite_setOrigin(game->parts[8].sprite, get_position(56, 34.5));
    sfSprite_setPosition(game->parts[8].sprite, get_position(1106, 834));
    sfSprite_setScale(game->parts[8].sprite, get_position(1.4, 1.4));
    game->parts[8].is_toggled = 0;
    game->parts[9].texture = sfTexture_createFromFile(
    "files/car_parts/hood_scoop.png", NULL);
    game->parts[9].sprite = get_sprite(game->parts[9].texture);
    sfSprite_setOrigin(game->parts[9].sprite, get_position(72, 38));
    sfSprite_setPosition(game->parts[9].sprite, get_position(1422, 838));
    sfSprite_setScale(game->parts[9].sprite, get_position(1.4, 1.4));
    game->parts[9].is_toggled = 0;
    game->parts[10].texture = sfTexture_createFromFile(
    "files/car_parts/radiator.png", NULL);
    game->parts[10].sprite = get_sprite(game->parts[10].texture);
    sfSprite_setPosition(game->parts[10].sprite, get_position(1345, 640));
    sfSprite_setScale(game->parts[10].sprite, get_position(1.8, 1.8));
    game->parts[10].is_toggled = 0; init_radiators(game);
}
