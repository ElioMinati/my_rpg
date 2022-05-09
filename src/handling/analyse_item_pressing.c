/*
** EPITECH PROJECT, 2022
** analyse_item_pressing
** File description:
** fucntions used to analyse
*/

#include "rpg.h"

static void analyse_more_item_pressing(game_t *game, int x, int y)
{
    if (x > 577 && x < 677 && y > 478 && y < 575 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 5);
    if (x > 729 && x < 829 && y > 478 && y < 575 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 6);
    if (x > 425 && x < 525 && y > 630 && y < 728 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 7);
    if (x > 577 && x < 677 && y > 630 && y < 728 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 8);
    if (x > 729 && x < 829 && y > 630 && y < 728 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 9);
}

void analyse_item_pressing(game_t *game, sfRenderWindow *win)
{
    int x = game->event.mouseButton.x;
    int y = game->event.mouseButton.y;

    if (x > 425 && x < 525 && y > 330 && y < 427 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 1);
    if (x > 577 && x < 677 && y > 330 && y < 427 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 2);
    if (x > 729 && x < 829 && y > 330 && y < 427 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 3);
    if (x > 425 && x < 525 && y > 478 && y < 575 && game->scene == 3 &&
    game->event.type == sfEvtMouseButtonPressed)
        select_car_item(game, 4);
    analyse_more_item_pressing(game, x, y);
}
