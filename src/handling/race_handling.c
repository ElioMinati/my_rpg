/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** race_handling
*/

#include "rpg.h"

void display_start_countdown(int number, sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/countdown.png", NULL);
    sfSprite *sprite = get_sprite(texture);

    sfSprite_setScale(sprite, get_position(10, 10));
    sfSprite_setPosition(sprite, get_position(900, 400));
    if (number == 3)
        sfSprite_setTextureRect(sprite, get_rect(0, 28, 10, 13));
    if (number == 2)
        sfSprite_setTextureRect(sprite, get_rect(0, 18, 10, 13));
    if (number == 1)
        sfSprite_setTextureRect(sprite, get_rect(0, 10, 8, 13));
    if (number == 0) {
        sfSprite_setTextureRect(sprite, get_rect(28, 19, 20, 13));
        sfSprite_setPosition(sprite, get_position(860, 400));
    }
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void handle_race_start(game_t *game, sfRenderWindow *win)
{
    game->race.race_clock.seconds = sfTime_asSeconds(
    sfClock_getElapsedTime(game->race.race_clock.clock));
    if (game->race.race_clock.seconds < 1) {
        display_start_countdown(3, win);
    }
    if (game->race.race_clock.seconds < 2 &&
    game->race.race_clock.seconds > 1) {
        display_start_countdown(2, win);
        game->race.fader = 0;
    }
    if (game->race.race_clock.seconds < 3 &&
    game->race.race_clock.seconds > 2)
        display_start_countdown(1, win);
    if (game->race.race_clock.seconds >= 3 &&
    game->race.race_clock.seconds < 4) {
        display_start_countdown(0, win);
        if (game->race.race_has_started == 0)
            game->race.gear_clock.clock = sfClock_create();
        game->race.race_has_started = 1;
    }
}
