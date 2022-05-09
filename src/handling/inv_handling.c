/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** inv_handling
*/

#include "rpg.h"
#include "my.h"

void inv_event(sfRenderWindow *window, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    check_binv_mouse(window, game);
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (pos.x > 1041 && pos.x < 1074 && pos.y > 742 && pos.y < 786
        && game->inv_page > 1)
            game->inv_page--;
        if (pos.x > 1388 && pos.x < 1421 && pos.y > 742 && pos.y < 786
        && game->inv_page < 10)
            game->inv_page++;
        check_binv_pos(window, game);
        game->event.type = sfEvtMouseButtonReleased;
    }
}

static void display_item_info(int place, game_t *game, sfRenderWindow *win)
{
    int item = place + (game->inv_page - 1) * 9 - 1;
    char *str = my_itoa(game->items[item].psi);

    str = my_strcat("PSI : ", str);
    if (game->nb_items >= item && game->scene == 2) {
        display_text(get_position(440, 480), game->items[item].name, 40, win);
        if (game->items[item].psi != 0)
            display_text(get_position(440, 530), str, 40, win);
    }
}

static void display_inv_info_third_line(sfRenderWindow *win, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    int x = game->event.mouseButton.x;
    int y = game->event.mouseButton.y;

    if (pos.x > 1025 && pos.x < 1125 && pos.y > 630 && pos.y < 728)
        display_item_info(7, game, win);
    if (pos.x > 1177 && pos.x < 1277 && pos.y > 630 && pos.y < 728)
        display_item_info(8, game, win);
    if (pos.x > 1329 && pos.x < 1429 && pos.y > 630 && pos.y < 728)
        display_item_info(9, game, win);
    if (x > 1025 && x < 1125 && y > 630 && y < 728 && game->scene == 3)
        select_item(game, 7);
    if (x > 1177 && x < 1277 && y > 630 && y < 728 && game->scene == 3)
        select_item(game, 8);
    if (x > 1329 && x < 1429 && y > 630 && y < 728 && game->scene == 3)
        select_item(game, 9);
    display_selected_item(game, win);
}

static void display_inv_info_second_line(sfRenderWindow *win, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    int x = game->event.mouseButton.x;
    int y = game->event.mouseButton.y;

    if (pos.x > 1025 && pos.x < 1125 && pos.y > 478 && pos.y < 575)
        display_item_info(4, game, win);
    if (pos.x > 1177 && pos.x < 1277 && pos.y > 478 && pos.y < 575)
        display_item_info(5, game, win);
    if (pos.x > 1329 && pos.x < 1429 && pos.y > 478 && pos.y < 575)
        display_item_info(6, game, win);
    if (x > 1025 && x < 1125 && y > 478 && y < 575 && game->scene == 3)
        select_item(game, 4);
    if (x > 1177 && x < 1277 && y > 478 && y < 575 && game->scene == 3)
        select_item(game, 5);
    if (x > 1329 && x < 1429 && y > 478 && y < 575 && game->scene == 3)
        select_item(game, 6);
    display_inv_info_third_line(win, game);
}

void display_inv_info_first_line(sfRenderWindow *win, game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    int x = game->event.mouseButton.x;
    int y = game->event.mouseButton.y;

    if (pos.x > 1025 && pos.x < 1125 && pos.y > 330 && pos.y < 427)
        display_item_info(1, game, win);
    if (pos.x > 1177 && pos.x < 1277 && pos.y > 330 && pos.y < 427)
        display_item_info(2, game, win);
    if (pos.x > 1329 && pos.x < 1429 && pos.y > 330 && pos.y < 427)
        display_item_info(3, game, win);
    if (x > 1025 && x < 1125 && y > 330 && y < 427 && game->scene == 3)
        select_item(game, 1);
    if (x > 1177 && x < 1277 && y > 330 && y < 427 && game->scene == 3)
        select_item(game, 2);
    if (x > 1329 && x < 1429 && y > 330 && y < 427 && game->scene == 3)
        select_item(game, 3);
    display_inv_info_second_line(win, game);
}
