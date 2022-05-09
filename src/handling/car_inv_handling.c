/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** inv_handling
*/

#include "rpg.h"
#include "my.h"

void select_car_item(game_t *game, int nb)
{
    if ((nb - 1) < game->current_car.nb_items) {
        game->current_car.item_selected = nb;
        game->inventory.selected = -1;
    }
    game->event.type = sfEvtMouseButtonReleased;
}

static void display_item_info(int place, game_t *game, sfRenderWindow *win)
{
    int item = place - 1;
    char *str = my_itoa(game->current_car.items[item].psi);

    str = my_strcat("PSI : ", str);
    if (game->current_car.nb_items > item) {
        display_text(get_position(100, 100),
        game->current_car.items[item].name, 20, win);
        if (game->current_car.items[item].psi != 0)
            display_text(get_position(100, 130), str, 20, win);
    }
}

static void display_inv_info_third_line(sfRenderWindow *win, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    int x = game->event.mouseButton.x;
    int y = game->event.mouseButton.y;

    if (pos.x > 425 && pos.x < 525 && pos.y > 630 && pos.y < 728)
        display_item_info(7, game, win);
    if (pos.x > 577 && pos.x < 677 && pos.y > 630 && pos.y < 728)
        display_item_info(8, game, win);
    if (pos.x > 729 && pos.x < 829 && pos.y > 630 && pos.y < 728)
        display_item_info(9, game, win);
    display_selected_car_item(game, win);
}

static void display_inv_info_second_line(sfRenderWindow *win, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    int x = game->event.mouseButton.x;
    int y = game->event.mouseButton.y;

    if (pos.x > 425 && pos.x < 525 && pos.y > 478 && pos.y < 575)
        display_item_info(4, game, win);
    if (pos.x > 577 && pos.x < 677 && pos.y > 478 && pos.y < 575)
        display_item_info(5, game, win);
    if (pos.x > 729 && pos.x < 829 && pos.y > 478 && pos.y < 575)
        display_item_info(6, game, win);
    display_inv_info_third_line(win, game);
}

void display_car_inv_info_first_line(sfRenderWindow *win, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    int x = game->event.mouseButton.x;
    int y = game->event.mouseButton.y;

    if (pos.x > 425 && pos.x < 525 && pos.y > 330 && pos.y < 427)
        display_item_info(1, game, win);
    if (pos.x > 577 && pos.x < 677 && pos.y > 330 && pos.y < 427)
        display_item_info(2, game, win);
    if (pos.x > 729 && pos.x < 829 && pos.y > 330 && pos.y < 427)
        display_item_info(3, game, win);
    display_inv_info_second_line(win, game);
}
