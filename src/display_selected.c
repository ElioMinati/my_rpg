/*
** EPITECH PROJECT, 2022
** display_selected.c
** File description:
** functions used to display the selected item
*/

#include "rpg.h"

static int can_equip(game_t *game, int index)
{
    for (int i = 0; i < game->current_car.nb_items; ++i) {
        if (game->current_car.items[i].type ==
        game->items[index + (game->inv_page - 1) * 9 - 1].type)
            return 0;
    }
    return 1;
}

void analyse_unequip_events(game_t *game, sfRenderWindow *win)
{
    if (game->current_car.item_selected != -1) {
        if (is_button_pressed(game, game->inv_buttons[3])) {
            sfSprite_setTextureRect(game->inv_buttons[3].sprite,
            get_rect(79, 0, 237, 79));
            unequip(game->current_car.item_selected, game, win);
        } else
            sfSprite_setTextureRect(game->inv_buttons[3].sprite,
            get_rect(0, 0, 237, 79));
    } else
        sfSprite_setTextureRect(game->inv_buttons[3].sprite,
        get_rect(0, 0, 237, 79));
}

void analyse_equip_events(game_t *game, sfRenderWindow *win)
{
    if (game->inventory.selected != -1 && can_equip(game,
    game->inventory.selected) == 0 &&
    is_button_pressed(game, game->inv_buttons[2])) {
        sfSprite_setTextureRect(game->inv_buttons[2].sprite,
        get_rect(43, 0, 101, 43));
        sfClock_restart(game->error_clock.clock);
        game->error_clock.error = 3;
    }
    if (game->inventory.selected != -1 &&
    can_equip(game, game->inventory.selected)) {
        if (is_button_pressed(game, game->inv_buttons[2])) {
            sfSprite_setTextureRect(game->inv_buttons[2].sprite,
            get_rect(43, 0, 101, 43));
            equip(game->inventory.selected, game, win);
        } else
            sfSprite_setTextureRect(game->inv_buttons[2].sprite,
            get_rect(0, 0, 101, 43));
    } else
        sfSprite_setTextureRect(game->inv_buttons[2].sprite,
        get_rect(0, 0, 101, 43));
}

void select_item(game_t *game, int nb)
{
    if ((game->inv_page - 1) * 9 + nb - 1 <= game->nb_items) {
        game->current_car.item_selected = -1;
        game->inventory.selected = nb;
    }
    game->event.type = sfEvtMouseButtonReleased;
}

void display_selected_item(game_t *game, sfRenderWindow *win)
{
    int i = game->inventory.selected;

    if (i == -1)
        return;
    if (i != 7) {
        draw_green_border_rect(get_position(1030 + 150 *
        ((i - 1) % 3), 330 + 150 * (i / 4)), get_position(100, 100),
        100, win);
    } else {
        draw_green_border_rect(get_position(1030 + 150 *
        ((i - 1) % 3), 330 + 150 * (i / 3)), get_position(100, 100),
        100, win);
    }
    sfRenderWindow_drawSprite(win, game->inv_buttons[2].sprite, NULL);
    if (is_button_hovered(win, game, game->inv_buttons[2]))
        draw_rect(sfSprite_getPosition(game->inv_buttons[2].sprite),
        get_position(101, 43), 100, win);
}
