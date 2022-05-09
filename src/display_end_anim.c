/*
** EPITECH PROJECT, 2022
** display_end_anim.c
** File description:
** function used to display the animation at the very end
*/

#include "rpg.h"

static void display_end_text_bubbles(game_t *game, sfRenderWindow *win)
{
    if (game->nb_bubble == 0)
        display_bubble(win, "files/misc/bubble11.png");
    if (game->nb_bubble == 1)
        display_bubble(win, "files/misc/bubble12.png");
    if (game->nb_bubble == 2)
        display_bubble(win, "files/misc/bubble13.png");
    if (game->nb_bubble == 3)
        display_bubble(win, "files/misc/bubble14.png");
    if (game->nb_bubble == 4)
        display_bubble(win, "files/misc/bubble15.png");
    if (game->nb_bubble == 5)
        display_bubble(win, "files/misc/bubble16.png");
    if (game->nb_bubble == 6) {
        sfSprite_setPosition(game->current_car.sprite, get_position(960, 590));
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        sfClock_restart(game->clock.clock);
        game->race.fader = 0;
        game->scene = 6;
        music_endgame(win, game, "files/music/end_theme.ogg");
    }
}

static void display_end_bubbles(game_t *game, sfRenderWindow *win)
{
    game->animation_clock.seconds = sfTime_asSeconds(sfClock_getElapsedTime(
    game->animation_clock.clock));
    if (game->animation_clock.seconds > 2) {
        draw_rect(get_position(800, 650), get_position(1120, 500), 150, win);
        display_adrian(win);
        display_end_text_bubbles(game, win);
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        ++game->nb_bubble;
        game->event.type = sfEvtMouseButtonReleased;
    }
    sfMusic_setPitch(game->music.music, 1);
    if ((sfTime_asSeconds(sfClock_getElapsedTime(
    game->animation_clock.clock)) / game->race.fader) > 0.02)
        game->race.fader++;
    if (game->race.fader < 255)
        draw_rect(get_position(0, 0), get_position(1920, 1080),
        255 - game->race.fader, win);
}

void display_end_anim(sfRenderWindow *win, game_t *game)
{
    display_window(win);
    sfRenderWindow_drawSprite(win, game->parallax[1].sprite, NULL);
    sfRenderWindow_drawSprite(win, game->parallax[0].sprite, NULL);
    sfRenderWindow_drawSprite(win, game->enemy_car.sprite, NULL);
    sfRenderWindow_drawSprite(win, game->current_car.sprite, NULL);
    if (is_button_pressed(game, game->main_buttons[11])) {
        sfSprite_setTextureRect(game->main_buttons[11].sprite,
        get_rect(43, 0, 85, 43));
        sfClock_restart(game->clock.clock); game->race.fader = 0; game->scene
        = 6; music_endgame(win, game, "files/music/end_theme.ogg");
        sfSprite_setPosition(game->current_car.sprite, get_position(960, 590));
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
    } else
        sfSprite_setTextureRect(game->main_buttons[11].sprite,
        get_rect(0, 0, 85, 43));
    display_end_bubbles(game, win);
    sfRenderWindow_drawSprite(win, game->main_buttons[11].sprite, NULL);
    if (is_button_hovered(win, game, game->main_buttons[11]))
        draw_rect(sfSprite_getPosition(game->main_buttons[11].sprite),
        get_position(85, 42), 100, win);
}
