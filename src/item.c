/*
** EPITECH PROJECT, 2022
** item
** File description:
** .
*/

#include "rpg.h"
#include "my.h"

static void display_arrow_inv(sfRenderWindow *win, game_t *game)
{
    sfSprite_setScale(game->inv_buttons[0].sprite, get_position(0.1, 0.1));
    sfSprite_setPosition(game->inv_buttons[0].sprite, get_position(1040, 740));
    sfSprite_setScale(game->inv_buttons[1].sprite, get_position(-0.1, 0.1));
    sfSprite_setPosition(game->inv_buttons[1].sprite, get_position(1420, 740));
    sfRenderWindow_drawSprite(win, game->inv_buttons[0].sprite, NULL);
    sfRenderWindow_drawSprite(win, game->inv_buttons[1].sprite, NULL);
    display_text(get_position(1230, 725), my_itoa(game->inv_page), 50, win);
}

void change_page(sfRenderWindow *win, game_t *game)
{
    if (is_button_pressed(game, game->inv_buttons[0]) && game->inv_page > 1) {
        game->inv_page--;
        game->inventory.selected = -1;
    }
    if (is_button_pressed(game, game->inv_buttons[1]) && game->inv_page < 10) {
        game->inv_page++;
        game->inventory.selected = -1;
    }
}

static void display_car_items(sfRenderWindow *win, game_t *game)
{
    for (int i = 0; i < game->current_car.nb_items; i++) {
        sfSprite_setPosition(game->current_car.items[i].sprite,
        get_position(475 + 150 * (game->current_car.items[i].pos % 3),
        370 + 150 * (game->current_car.items[i].pos / 3)));
        sfSprite_setScale(game->current_car.items[i].sprite,
        get_position(0.7, 0.7));
        sfRenderWindow_drawSprite(win, game->current_car.items[i].sprite, NULL);
    }
}

void display_item(sfRenderWindow *win, game_t *game)
{
    display_inv_info_first_line(win, game);
    display_arrow_inv(win, game);
    change_page(win, game);
    display_text(get_position(1110, 210), "INVENTORY", 50, win);
    for (int i = 0; i <= game->nb_items; i++) {
        if (game->items[i].page == game->inv_page) {
            sfSprite_setPosition(game->items[i].sprite, get_position(1075 +
            150 * (game->items[i].pos % 3), 370 + 150 *
            (game->items[i].pos / 3)));
            sfSprite_setScale(game->items[i].sprite, get_position(0.7, 0.7));
            sfRenderWindow_drawSprite(win, game->items[i].sprite, NULL);
        }
    }
    if (game->current_car.nb_items != 0 && game->scene == 3) {
        display_car_inv_info_first_line(win, game);
        display_car_items(win, game);
    }
}
