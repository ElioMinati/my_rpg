/*
** EPITECH PROJECT, 2022
** equip.c
** File description:
** functions used to equip items onto cars
*/

#include "rpg.h"

static item_t *realloc_items(game_t *game)
{
    item_t *new_items = malloc((game->current_car.nb_items + 1) *
    sizeof(item_t));

    for (int i = 0; i < game->current_car.nb_items; ++i) {
        new_items[i].gain = game->current_car.items[i].gain;
        new_items[i].name = game->current_car.items[i].name;
        new_items[i].page = game->current_car.items[i].page;
        new_items[i].pos = game->current_car.items[i].pos;
        new_items[i].psi = game->current_car.items[i].psi;
        new_items[i].type = game->current_car.items[i].type;
        new_items[i].texture = sfSprite_getTexture(
        game->current_car.items[i].sprite);
        new_items[i].sprite = get_sprite(new_items[i].texture);
        sfSprite_setOrigin(new_items[i].sprite,
        sfSprite_getOrigin(game->current_car.items[i].sprite));
    }
    return new_items;
}

static void add_item(item_t *items, game_t *game, item_t item)
{
    int i = game->current_car.nb_items;

    items[i].gain = item.gain;
    items[i].name = item.name;
    items[i].page = 1;
    items[i].pos = game->current_car.nb_items;
    items[i].psi = item.psi;
    items[i].type = item.type;
    items[i].texture = sfSprite_getTexture(item.sprite);
    items[i].sprite = get_sprite(items[i].texture);
    sfSprite_setOrigin(items[i].sprite,
    sfSprite_getOrigin(item.sprite));
}

static void remove_from_items(game_t *game, int index)
{
    item_t *new_items = malloc((game->nb_items) *
    sizeof(item_t));
    int j = 0;

    for (int i = 0; i <= game->nb_items; ++i) {
        if (i == index)
            continue;
        new_items[j].gain = game->items[i].gain;
        new_items[j].name = game->items[i].name;
        remove_item_first(new_items, game, j, i);
        ++j;
    }
    game->nb_items -= 1;
    game->items = new_items;
}

void equip(int index, game_t *game, sfRenderWindow *window)
{
    if (game->current_car.nb_items == 0) {
        game->current_car.items = malloc(1 * sizeof(item_t));
        game->garage[game->current_car.garage_pos].items =
        malloc(1 * sizeof(item_t));
    } else {
        game->current_car.items = realloc_items(game);
        game->garage[game->current_car.garage_pos].items =
        realloc_items(game);
    }
    add_item(game->garage[game->current_car.garage_pos].items,
    game, game->items[index + (game->inv_page - 1) * 9 - 1]);
    add_item(game->current_car.items, game, game->items[index +
    (game->inv_page - 1) * 9 - 1]);
    ++game->current_car.nb_items;
    ++game->garage[game->current_car.garage_pos].nb_items;
    tune(game, game->items[index + (game->inv_page - 1) * 9 - 1]);
    remove_from_items(game, index + (game->inv_page - 1) * 9 - 1);
    game->inventory.selected = -1;
}
