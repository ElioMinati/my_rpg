/*
** EPITECH PROJECT, 2022
** remove_items.c
** File description:
** remove
*/

#include "rpg.h"

void remove_item_garage(item_t *new_items, game_t *game, int j, int i)
{
    int posi = game->current_car.garage_pos;

    if (i > j) {
        new_items[j].page = game->garage[posi].items[i - 1].page;
        new_items[j].pos = game->garage[posi].items[i - 1].pos;
    } else {
        new_items[j].page = game->garage[posi].items[i].page;
        new_items[j].pos = game->garage[posi].items[i].pos;
    }
    new_items[j].psi = game->garage[posi].items[i].psi;
    new_items[j].type = game->garage[posi].items[i].type;
    new_items[j].texture = sfSprite_getTexture(
    game->garage[posi].items[i].sprite);
    new_items[j].sprite = get_sprite(new_items[j].texture);
    sfSprite_setOrigin(new_items[j].sprite,
    sfSprite_getOrigin(game->garage[posi].items[i].sprite));
}

void remove_item(item_t *new_items, game_t *game, int j, int i)
{
    if (i > j) {
        new_items[j].page = game->current_car.items[i - 1].page;
        new_items[j].pos = game->current_car.items[i - 1].pos;
    } else {
        new_items[j].page = game->current_car.items[i].page;
        new_items[j].pos = game->current_car.items[i].pos;
    }
    new_items[j].psi = game->current_car.items[i].psi;
    new_items[j].type = game->current_car.items[i].type;
    new_items[j].texture = sfSprite_getTexture(
    game->current_car.items[i].sprite);
    new_items[j].sprite = get_sprite(new_items[j].texture);
    sfSprite_setOrigin(new_items[j].sprite,
    sfSprite_getOrigin(game->current_car.items[i].sprite));
}

void remove_item_first(item_t *new_items, game_t *game, int j, int i)
{
    if (i > j) {
        new_items[j].page = game->items[i - 1].page;
        new_items[j].pos = game->items[i - 1].pos;
    } else {
        new_items[j].page = game->items[i].page;
        new_items[j].pos = game->items[i].pos;
    }
    new_items[j].psi = game->items[i].psi;
    new_items[j].type = game->items[i].type;
    new_items[j].texture = sfSprite_getTexture(
    game->items[i].sprite);
    new_items[j].sprite = get_sprite(new_items[j].texture);
    sfSprite_setOrigin(new_items[j].sprite,
    sfSprite_getOrigin(game->items[i].sprite));
}
