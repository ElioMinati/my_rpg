/*
** EPITECH PROJECT, 2022
** display_garage_cars
** File description:
** functions used to display the garage cars
*/

#include "rpg.h"

void display_selected_car_item(game_t *game, sfRenderWindow *win)
{
    int i = game->current_car.item_selected;

    if (i == -1)
        return;
    if (i != 7) {
        draw_green_border_rect(get_position(430 + 150 *
        ((i - 1) % 3), 330 + 150 * (i / 4)), get_position(100, 100),
        100, win);
    } else {
        draw_green_border_rect(get_position(430 + 150 *
        ((i - 1) % 3), 330 + 150 * (i / 3)), get_position(100, 100),
        100, win);
    }
    sfRenderWindow_drawSprite(win, game->inv_buttons[3].sprite, NULL);
    if (is_button_hovered(win, game, game->inv_buttons[3]))
        draw_rect(sfSprite_getPosition(game->inv_buttons[3].sprite),
        get_position(118.5, 37.5), 100, win);
}

void display_garage_cars(car_t *garage, sfRenderWindow *win)
{
    for (int i = 0; i < garage->nb_cars; ++i) {
        if (sfSprite_getPosition(garage[i].sprite).x < 1900 &&
        sfSprite_getPosition(garage[i].sprite).x > 200)
            sfRenderWindow_drawSprite(win, garage[i].sprite, NULL);
    }
    if (garage->selected == 0)
        draw_green_border_rect(get_position(200, 435),
        get_position(430, 230), 0, win);
    if (garage->selected == 1)
        draw_green_border_rect(get_position(740, 435),
        get_position(430, 230), 0, win);
    if (garage->selected == 2)
        draw_green_border_rect(get_position(1290, 435),
        get_position(430, 230), 0, win);
}
