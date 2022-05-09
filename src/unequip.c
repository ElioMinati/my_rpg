/*
** EPITECH PROJECT, 2022
** equip.c
** File description:
** functions used to equip items onto cars
*/

#include "rpg.h"

static item_t *realloc_items(game_t *game)
{
    item_t *new_items = malloc((game->nb_items + 2) *
    sizeof(item_t));

    for (int i = 0; i <= game->nb_items; ++i) {
        new_items[i].gain = game->items[i].gain;
        new_items[i].name = game->items[i].name;
        new_items[i].page = game->items[i].page;
        new_items[i].pos = game->items[i].pos;
        new_items[i].psi = game->items[i].psi;
        new_items[i].type = game->items[i].type;
        new_items[i].texture = sfSprite_getTexture(
        game->items[i].sprite);
        new_items[i].sprite = get_sprite(new_items[i].texture);
        sfSprite_setOrigin(new_items[i].sprite,
        sfSprite_getOrigin(game->items[i].sprite));
    }
    return new_items;
}

static void add_item(item_t *items, game_t *game, item_t item)
{
    int i = game->nb_items + 1;

    items[i].gain = item.gain;
    items[i].name = item.name;
    items[i].page = (i + 1) / 9 + 1;
    items[i].pos = i % 9;
    items[i].psi = item.psi;
    items[i].type = item.type;
    items[i].texture = sfSprite_getTexture(item.sprite);
    items[i].sprite = get_sprite(items[i].texture);
    sfSprite_setOrigin(items[i].sprite,
    sfSprite_getOrigin(item.sprite));
}

static void remove_from_items_garage(game_t *game, int index)
{
    int posi = game->current_car.garage_pos;
    item_t *new_items = malloc(game->garage[posi].nb_items *
    sizeof(item_t));
    int j = 0;

    for (int i = 0; i < game->garage[posi].nb_items; ++i) {
        if (i == index)
            continue;
        new_items[j].gain = game->garage[posi].items[i].gain;
        new_items[j].name = game->garage[posi].items[i].name;
        remove_item_garage(new_items, game, j, i);
        ++j;
    }
    game->garage[posi].nb_items -= 1;
    game->garage[posi].items = new_items;
}

static void remove_from_items(game_t *game, int index)
{
    item_t *new_items = malloc(game->current_car.nb_items *
    sizeof(item_t));
    int j = 0;

    for (int i = 0; i < game->current_car.nb_items; ++i) {
        if (i == index)
            continue;
        new_items[j].gain = game->current_car.items[i].gain;
        new_items[j].name = game->current_car.items[i].name;
        remove_item(new_items, game, j, i);
        ++j;
    }
    game->current_car.nb_items -= 1;
    game->current_car.items = new_items;
}

void unequip(int index, game_t *game, sfRenderWindow *window)
{
    if (game->nb_items == -1)
        game->items = malloc(1 * sizeof(item_t));
    else
        game->items = realloc_items(game);
    add_item(game->items, game, game->current_car.items[index - 1]);
    ++game->nb_items;
    detune(game, game->current_car.items[index - 1]);
    remove_from_items(game, index - 1);
    remove_from_items_garage(game, index - 1);
    game->current_car.item_selected = -1;
}
