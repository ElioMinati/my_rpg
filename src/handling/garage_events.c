/*
** EPITECH PROJECT, 2022
** garage_events
** File description:
** functions used to hanlde garage events
*/

#include "rpg.h"

static int get_selected_car(car_t *garage)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; i < garage->nb_cars; ++i) {
        pos = sfSprite_getPosition(garage[i].sprite);
        if (pos.x > 100 && pos.x < 500 && (i + garage->selected) <
        garage->nb_cars)
            return (i + garage->selected);
    }
    return -1;
}

static void detect_third_car_pressing(game_t *game)
{
    if (game->event.mouseButton.x > 1290 && game->event.mouseButton.x < 1620
    && game->event.mouseButton.y > 435 && game->event.mouseButton.y < 665 &&
    game->garage->nb_cars > 2) {
        game->garage->selected = 2;
        set_current_car(game, game->garage[get_selected_car(game->garage)],
        get_selected_car(game->garage));
    }
}

void detect_garage_car_pressing(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        game->event.type = sfEvtMouseButtonReleased;
        if (game->event.mouseButton.x > 200 && game->event.mouseButton.x < 730
        && game->event.mouseButton.y > 435 && game->event.mouseButton.y < 665) {
            game->garage->selected = 0;
            set_current_car(game, game->garage[get_selected_car(game->garage)],
            get_selected_car(game->garage));
        }
        if (game->event.mouseButton.x > 740 && game->event.mouseButton.x < 1180
        && game->event.mouseButton.y > 435 && game->event.mouseButton.y < 665 &&
        game->garage->nb_cars > 1) {
            game->garage->selected = 1;
            set_current_car(game, game->garage[get_selected_car(game->garage)],
            get_selected_car(game->garage));
        }
        detect_third_car_pressing(game);
    }
}