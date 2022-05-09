/*
** EPITECH PROJECT, 2022
** analyse_purchase_item
** File description:
** .
*/

#include "rpg.h"
#include "my.h"

static void check_selectede(game_t *game)
{
    check_money(game, 6, 249, 0);
    if (game->parts->selected == 6 && game->money >= 249) {
        game->nb_items++;
        game->money -= 249;
        game->money_spend += 249;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 17);
        game->items[game->nb_items].name = "Sport Air Filter";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.1;
        game->items[game->nb_items].type = AIR_FILTER;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/sport_air_filter.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(35.5, 37.5));
    }
    check_selectedf(game);
}

static void check_selectedd(game_t *game)
{
    check_money(game, 3, 18799, 3000);
    if (game->parts->selected == 3 && game->money >= 18799
        && my_atoi(game->xp) >= 3000) {
        game->nb_items++;
        game->money -= 18799;
        game->money_spend += 18799;
        game->items[game->nb_items].psi = 32;
        game->items[game->nb_items].name = malloc(sizeof(char) * 14);
        game->items[game->nb_items].name = "Diamond turbo";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 2.8;
        game->items[game->nb_items].type = TURBO;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/diamond_turbo.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(50.5, 50.5));
    }
    check_selectede(game);
}

static void check_selectedc(game_t *game)
{
    check_money(game, 2, 7680, 1000);
    if (game->parts->selected == 2 && game->money >= 7680
        && my_atoi(game->xp) >= 1000) {
        game->nb_items++;
        game->money -= 7680;
        game->money_spend += 7680;
        game->items[game->nb_items].psi = 17;
        game->items[game->nb_items].name = malloc(sizeof(char) * 9);
        game->items[game->nb_items].name = "Bi-turbo";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 2;
        game->items[game->nb_items].type = TURBO;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/bi-turbo.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(46.5, 45.5));
    }
    check_selectedd(game);
}

void check_selectedb(game_t *game)
{
    check_money(game, 1, 1240, 500);
    if (game->parts->selected == 1 && game->money >= 1240
        && my_atoi(game->xp) >= 500) {
        game->nb_items++;
        game->money -= 1240;
        game->money_spend += 1240;
        game->items[game->nb_items].psi = 7;
        game->items[game->nb_items].name = malloc(sizeof(char) * 14);
        game->items[game->nb_items].name = "Regular turbo";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.5;
        game->items[game->nb_items].type = TURBO;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/turbo.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(49.9, 49.5));
    }
    check_selectedc(game);
}

void check_selected(game_t *game)
{
    check_money(game, 0, 650, 0);
    if (game->parts->selected == 0 && game->money >= 650) {
        game->nb_items++;
        game->money -= 650;
        game->money_spend += 650;
        game->items[game->nb_items].psi = 4;
        game->items[game->nb_items].name = malloc(sizeof(char) * 12);
        game->items[game->nb_items].name = "Small turbo";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.2;
        game->items[game->nb_items].type = TURBO;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/small_turbo.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(37, 37));
    }
    check_selectedb(game);
}
