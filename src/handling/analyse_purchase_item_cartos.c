/*
** EPITECH PROJECT, 2022
** analyse_purchase_item_3.c
** File description:
** .
*/

#include "rpg.h"
#include "my.h"

static void check_selectedo(game_t *game)
{
    check_money(game, 19, 7930, 3000);
    if (game->parts->selected == 19 && game->money >= 7930
    && my_atoi(game->xp) >= 3000) {
        game->nb_items++;
        game->money -= 7930;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 22);
        game->items[game->nb_items].name = "Golden coated pistons";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.2;
        game->items[game->nb_items].type = PISTON;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/best_forged.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(29.5, 65));
    }
    check_selectedp(game);
}

static void check_selectedn(game_t *game)
{
    check_money(game, 18, 5600, 1000);
    if (game->parts->selected == 18 && game->money >= 5600
    && my_atoi(game->xp) >= 1000) {
        game->nb_items++;
        game->money -= 5600;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 15);
        game->items[game->nb_items].name = "forged pistons";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.13;
        game->items[game->nb_items].type = PISTON;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/better_forged.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(30, 66));
    }
    check_selectedo(game);
}

static void check_selectedm(game_t *game)
{
    check_money(game, 17, 2470, 0);
    if (game->parts->selected == 17 && game->money >= 2470) {
        game->nb_items++;
        game->money -= 2470;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 19);
        game->items[game->nb_items].name = "Reinforced pistons";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.08;
        game->items[game->nb_items].type = PISTON;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/forged.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(30, 65));
    }
    check_selectedn(game);
}

static void check_selectedl(game_t *game)
{
    check_money(game, 15, 2790, 3000);
    if (game->parts->selected == 15 && game->money >= 2790
        && my_atoi(game->xp) >= 3000) {
        game->nb_items++;
        game->money -= 2790;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 19);
        game->items[game->nb_items].name = "pr racing radiator";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.3;
        game->items[game->nb_items].type = RADIATOR;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/black_PR_radiator.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(62, 27));
    }
    check_selectedm(game);
}

void check_selectedk(game_t *game)
{
    check_money(game, 14, 1670, 1000);
    if (game->parts->selected == 14 && game->money >= 1670
    && my_atoi(game->xp) >= 1000) {
        game->nb_items++;
        game->money -= 1670;
        game->items[game->nb_items].psi = 0;
        game->items[game->nb_items].name = malloc(sizeof(char) * 17);
        game->items[game->nb_items].name = "Diamond radiator";
        game->items[game->nb_items].page = (game->nb_items) / 9 + 1;
        game->items[game->nb_items].pos = (game->nb_items) % 9;
        game->items[game->nb_items].gain = 1.2;
        game->items[game->nb_items].type = RADIATOR;
        game->items[game->nb_items].texture = sfTexture_createFromFile(
        "files/car_parts/diamond_radiator.png", NULL);
        game->items[game->nb_items].sprite = get_sprite(
        game->items[game->nb_items].texture);
        sfSprite_setOrigin(game->items[game->nb_items].sprite,
        get_position(62, 27));
    }
    check_selectedl(game);
}
