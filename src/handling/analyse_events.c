/*
** EPITECH PROJECT, 2022
** analyse_events?c
** File description:
** functions used to analyse all kind of specific events
*/

#include "rpg.h"

static void detect_car_hover(game_t *game, sfVector2i mouse)
{
    if (mouse.x > 100 && mouse.y > 530 && mouse.x < 500 && mouse.y < 700)
        sfSprite_setScale(game->cars[0].sprite, get_position(1.2, 1.2));
    else
        sfSprite_setScale(game->cars[0].sprite, get_position(1, 1));
    if (mouse.x > 700 && mouse.y > 538 && mouse.x < 1130 && mouse.y < 700)
        sfSprite_setScale(game->cars[1].sprite, get_position(1.2, 1.2));
    else
        sfSprite_setScale(game->cars[1].sprite, get_position(1, 1));
    if (mouse.x > 1320 && mouse.y > 530 && mouse.x < 1810 && mouse.y < 700)
        sfSprite_setScale(game->cars[2].sprite, get_position(1.2, 1.2));
    else
        sfSprite_setScale(game->cars[2].sprite, get_position(1, 1));
}

static void detect_car_released(game_t *game, sfVector2i mouse)
{
    if (game->event.mouseButton.x > 100 && game->event.mouseButton.x < 500
    && game->event.mouseButton.y > 530 &&
    game->event.mouseButton.y < 700) {
        game->scene = 9;
        game->animation_clock.clock = sfClock_create();
        (game, game->cars[0]);
        transfer_car_to_garage(game, game->garage, game->cars[0], 0);
        game->current_car.anim = sfClock_create();
        set_current_car(game, game->garage[0], 0);
        set_anim_race(game);
    }
    if (game->event.mouseButton.x > 700 && game->event.mouseButton.x < 1130
    && game->event.mouseButton.y > 538 &&
    game->event.mouseButton.y < 700) {
        game->scene = 9;
        game->animation_clock.clock = sfClock_create();
        transfer_car_to_garage(game, game->garage, game->cars[1], 0);
        game->current_car.anim = sfClock_create();
        set_current_car(game, game->garage[0], 0);
        set_anim_race(game);
    }
    if (game->event.mouseButton.x > 1320 && game->event.mouseButton.x < 1810
    && game->event.mouseButton.y > 530 && game->event.mouseButton.y < 700) {
        game->scene = 9;
        game->animation_clock.clock = sfClock_create();
        transfer_car_to_garage(game, game->garage, game->cars[2], 0);
        game->current_car.anim = sfClock_create();
        set_current_car(game, game->garage[0], 0);
        set_anim_race(game);
    }
}

static void analyse_car_choice(game_t *game, sfVector2i mouse)
{
    detect_car_hover(game, mouse);
    if (game->event.type == sfEvtMouseButtonReleased)
        detect_car_released(game, mouse);
    if (game->event.type == sfEvtMouseButtonPressed)
        detect_car_pressed(game, mouse);
}

static void analyse_garage_enter(game_t *game, sfVector2i mouse,
sfRenderWindow *win)
{
    sfVector2f pos = sfSprite_getPosition(game->backgrounds[3].sprite);

    if (pos.y > -150 && pos.x < -60 && pos.x > -1500) {
        display_text(get_position(570, 800), "Press E to enter the dealership",
        50, win);
        display_text(get_position(570, 900), "Press F to enter the parts shop",
        50, win);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            set_dealership_cars(game);
            sfSprite_setPosition(game->dealership_buttons[2].sprite,
            get_position(850, 900));
            game->scene = 4;
        }
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            game->scene = 8;
        }
    }
    if (pos.y > -1000 && pos.y < -480 && pos.x < -450 && pos.x > -1000) {
        display_text(get_position(640, 900), "Press E to enter the garage",
        50, win);
        if (sfKeyboard_isKeyPressed(sfKeyE))
            game->scene = 3;
    }
    if (pos.y > -550 && pos.y < -250 && pos.x < 100 && pos.x > -100) {
        display_text(get_position(700, 900), "Press E to race",
        50, win);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            game->scene = 5;
            set_race(game);
        }
    }
    handle_leandre(win, game);
}

void analyse_events(sfRenderWindow *win, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);

    if (game->scene == 1)
        analyse_car_choice(game, mouse);
    if (game->scene == 2) {
        if (game->pause == 1) {
            analyse_pause_events(game, win);
            return;
        }
        analyse_garage_enter(game, mouse, win);
        analyse_speedlist_events(game, mouse, win);
        if (game->inventory.status == 1)
            change_page(win, game);
    }
    if (game->scene == 3)
        analyse_garage_events(game, mouse, win);
        if (game->inventory.status == 1)
            change_page(win, game);
}
