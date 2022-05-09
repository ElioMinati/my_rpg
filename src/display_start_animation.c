/*
** EPITECH PROJECT, 2022
** display_start_animation
** File description:
** functions used to display the start animation
*/

#include "rpg.h"



static void anim_handling(game_t *game, sfRenderWindow *window)
{
    if (game->race.race_clock.seconds > 3) {
        sfSprite_move(game->enemy_car.sprite,
        get_position(game->race.race_clock.seconds * 100 - 300, 0));
    }
    if (game->race.race_clock.seconds > 5) {
        do_fader(game, window);
    }
}

void display_bubbles(game_t *game, sfRenderWindow *window)
{
    if (game->nb_bubble < 5) {
        draw_rect(get_position(800, 650), get_position(1120, 500), 150, window);
        display_adrian(window);
        if ((sfTime_asSeconds(sfClock_getElapsedTime(
        game->animation_clock.clock)) / game->race.fader) > 0.02)
            game->race.fader++;
        if (game->race.fader < 255)
            draw_rect(get_position(0, 0), get_position(1920, 1080),
            255 - game->race.fader, window);
        display_text_bubbles(window, game,
        sfTime_asSeconds(sfClock_getElapsedTime(game->animation_clock.clock)));
    } else {
        handle_race_start(game, window);
        anim_handling(game, window);
    }
}

void do_fader(game_t *game, sfRenderWindow *win)
{
    if (game->race.fader == 0) {
        sfClock_restart(game->animation_clock.clock);
        game->race.fader = 1;
    }
    if ((sfTime_asSeconds(sfClock_getElapsedTime(
    game->animation_clock.clock)) / game->race.fader) > 0.015)
        game->race.fader++;
    if (game->race.fader >= 255) {
        game->scene = 2;
        sfSprite_setPosition(game->current_car.sprite, get_position(960, 590));
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        init_particles(game);
    }
    draw_rect(get_position(0, 0), get_position(1920, 1080),
    game->race.fader, win);
}
