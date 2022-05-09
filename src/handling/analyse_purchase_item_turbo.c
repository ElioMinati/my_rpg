/*
** EPITECH PROJECT, 2022
** analyse_purchase_item_2
** File description:
** .
*/

#include "rpg.h"
#include "my.h"

static void check_selectedj(game_t *game)
{
    check_money(game, 13, 540, 500);
    if (game->parts->selected == 13 && game->money >= 540
        && my_atoi(game->xp) >= 500) {
        game->nb_items++;
        game->money -= 540;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 12);
        game->items[game->nb_items].name = "Pr radiator";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.13;
        game->items[game->nb_items].type = RADIATOR;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/Pr_radiator.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(62, 27));
    }
    check_selectedk(game);
}

static void check_selectedi(game_t *game)
{
    check_money(game, 12, 150, 0);
    if (game->parts->selected == 12 && game->money >= 150) {
        game->nb_items++;
        game->money -= 150;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 15);
        game->items[game->nb_items].name = "Sport radiator";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.08;
        game->items[game->nb_items].type = RADIATOR;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/radiator2.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(62, 27));
    }
    check_selectedj(game);
}

static void check_selectedh(game_t *game)
{
    check_money(game, 9, 4390, 3000);
    if (game->parts->selected == 9 && game->money >= 4390
        && my_atoi(game->xp) >= 3000) {
        game->nb_items++;
        game->money -= 4390;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 11);
        game->items[game->nb_items].name = "Hood scoop";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.5;
        game->items[game->nb_items].type = AIR_FILTER;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/hood_scoop.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(72, 38));
    }
    check_selectedi(game);
}

static void check_selectedg(game_t *game)
{
    check_money(game, 8, 2480, 1000);
    if (game->parts->selected == 8 && game->money >= 2480
        && my_atoi(game->xp) >= 1000) {
        game->nb_items++;
        game->money -= 2480;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 10);
        game->items[game->nb_items].name = "Downpipes";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.3;
        game->items[game->nb_items].type = AIR_FILTER;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/weird_air_filter.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(56, 34.5));
    }
    check_selectedh(game);
}

void check_selectedf(game_t *game)
{
    check_money(game, 8, 910, 500);
    if (game->parts->selected == 7 && game->money >= 910
        && my_atoi(game->xp) >= 500) {
        game->nb_items++;
        game->money -= 910;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 16);
        game->items[game->nb_items].name = "Race Air Filter";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.15;
        game->items[game->nb_items].type = AIR_FILTER;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/really_sport_air_filter.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(35, 34));
    }
    check_selectedg(game);
}