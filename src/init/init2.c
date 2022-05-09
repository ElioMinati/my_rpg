/*
** EPITECH PROJECT, 2022
** init2
** File description:
** .
*/

#include "rpg.h"

void init_inventory(game_t *game)
{
    game->inventory.button_texture =
    sfTexture_createFromFile("files/buttons/box.png", NULL);
    game->inventory.button_sprite = sfSprite_create();
    game->inventory.texture =
    sfTexture_createFromFile("files/misc/inv.png", NULL);
    game->inventory.sprite = get_sprite(game->inventory.texture);
    sfSprite_setPosition(game->inventory.button_sprite, get_position(1750,
    870));
    sfSprite_setScale(game->inventory.button_sprite, get_position(2, 2));
    sfSprite_setPosition(game->inventory.sprite, get_position(300, 100));
    sfSprite_setScale(game->inventory.sprite, get_position(25, 25));
    sfSprite_setTexture(game->inventory.button_sprite,
    game->inventory.button_texture, sfTrue);
    sfSprite_setTexture(game->inventory.sprite,
    game->inventory.texture, sfTrue);
    sfSprite_setTextureRect(game->inventory.button_sprite,
    game->inventory.rect);
    game->inventory.status = 0;
    game->inventory.selected = -1;
}

void init_race(game_t *game)
{
    game->parallax = malloc(2 * sizeof(background_t));
    game->parallax[0].texture =
    sfTexture_createFromFile("files/background/road_start.png", NULL);
    game->parallax[0].sprite = get_sprite(game->parallax[0].texture);
    sfSprite_setPosition(game->parallax[0].sprite, get_position(0, 0));
    sfSprite_setScale(game->parallax[0].sprite, get_position(2, 2));
    sfSprite_setTexture(game->parallax[0].sprite,
    game->parallax[0].texture, sfTrue);
    game->parallax[1].texture =
    sfTexture_createFromFile("files/background/sunset.png", NULL);
    game->parallax[1].sprite = get_sprite(game->parallax[1].texture);
    sfSprite_setPosition(game->parallax[1].sprite, get_position(0, 0));
    sfSprite_setTexture(game->parallax[1].sprite,
    game->parallax[1].texture, sfTrue);
    game->key = rand() % 25;
}

void init_button_start(game_t *game)
{
    game->main_buttons[0].rect = (sfIntRect){0, 0, 157, 77};
    game->main_buttons[0].texture = sfTexture_createFromFile
    ("files/buttons/button_start.png", NULL);
    game->main_buttons[0].sprite = sfSprite_create();
    sfSprite_setTexture(game->main_buttons[0].sprite,
    game->main_buttons[0].texture, sfTrue);
    sfSprite_setScale(game->main_buttons[0].sprite, get_position(2, 2));
    sfSprite_setPosition(game->main_buttons[0].sprite, get_position(800, 816));
    sfSprite_setTextureRect(game->main_buttons[0].sprite,
    game->main_buttons[0].rect);
}

void init_button_quit(game_t *game)
{
    game->main_buttons[2].texture = sfTexture_createFromFile
    ("files/buttons/exit.png", NULL);
    game->main_buttons[2].sprite = get_sprite(game->main_buttons[2].texture);
    game->main_buttons[2].rect = get_rect(0, 0, 34, 13);
    sfSprite_setScale(game->main_buttons[2].sprite, get_position(6, 6));
    sfSprite_setPosition(game->main_buttons[2].sprite, get_position(10, 940));
    sfSprite_setTexture(game->main_buttons[2].sprite,
    game->main_buttons[2].texture, sfTrue);
    sfSprite_setTextureRect(game->main_buttons[2].sprite,
    game->main_buttons[2].rect);
    game->main_buttons[3].texture = sfTexture_createFromFile
    ("files/buttons/info.png", NULL);
    game->main_buttons[3].sprite = get_sprite(game->main_buttons[3].texture);
    game->main_buttons[3].rect = get_rect(0, 0, 34, 13);
    sfSprite_setScale(game->main_buttons[3].sprite, get_position(0.35, 0.35));
    sfSprite_setPosition(game->main_buttons[3].sprite, get_position(1820, 10));
}

void init_logo(game_t *game)
{
    game->main_buttons[1].texture = sfTexture_createFromFile(
    "files/misc/logo.png", NULL);
    game->main_buttons[1].sprite = get_sprite(game->main_buttons[1].texture);
    sfSprite_setPosition(game->main_buttons[1].sprite, get_position(450, 450));
    sfSprite_setScale(game->main_buttons[1].sprite, get_position(7, 7));
    game->backgrounds[7].texture = sfTexture_createFromFile(
    "files/misc/skyline_logo.png", NULL);
    game->backgrounds[7].sprite = get_sprite(game->backgrounds[7].texture);
    sfSprite_setPosition(game->backgrounds[7].sprite, get_position(700, 50));
    sfSprite_setScale(game->backgrounds[7].sprite, get_position(2, 2));
    game->backgrounds[11].texture = sfTexture_createFromFile(
    "files/background/sunrise.png", NULL);
    game->backgrounds[11].sprite = get_sprite(game->backgrounds[11].texture);
    sfSprite_setPosition(game->backgrounds[11].sprite, get_position(0, 0));
    sfSprite_setScale(game->backgrounds[11].sprite, get_position(1, 1));
}
