/*
** EPITECH PROJECT, 2022
** analyse_purchase_item_4
** File description:
** .
*/

#include "rpg.h"
#include "my.h"

static void check_selecteds(game_t *game)
{
    check_money(game, 24, 4290, 3000);
    if (game->parts->selected == 24 && game->money >= 4290
    && my_atoi(game->xp) >= 3000) {
        game->nb_items++;
        game->money -= 4290;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 18);
        game->items[game->nb_items].name = "Type R 2 step map";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.35;
        game->items[game->nb_items].type = MAP;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/godmode.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(49, 57));
    }
}

static void check_selectedr(game_t *game)
{
    check_money(game, 23, 3450, 1000);
    if (game->parts->selected == 23 && game->money >= 3450
    && my_atoi(game->xp) >= 1000) {
        game->nb_items++;
        game->money -= 3450;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 11);
        game->items[game->nb_items].name = "Type R map";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.25;
        game->items[game->nb_items].type = MAP;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/carto_type_r_pro.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(49, 50));
    }
    check_selecteds(game);
}

static void check_selectedq(game_t *game)
{
    check_money(game, 22, 1340, 500);
    if (game->parts->selected == 22 && game->money >= 1340
    && my_atoi(game->xp) >= 500) {
        game->nb_items++;
        game->money -= 1340;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 10);
        game->items[game->nb_items].name = "Sport map";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.14;
        game->items[game->nb_items].type = MAP;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/speeeeed.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(49, 50));
    }
    check_selectedr(game);
}

void check_selectedp(game_t *game)
{
    check_money(game, 21, 710, 0);
    if (game->parts->selected == 21 && game->money >= 710) {
        game->nb_items++;
        game->money -= 710;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 11);
        game->items[game->nb_items].name = "2 step map";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.09;
        game->items[game->nb_items].type = MAP;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/2step.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(49, 59));
    }
    check_selectedq(game);
}
