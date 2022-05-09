/*
** EPITECH PROJECT, 2022
** race_end.c
** File description:
** display end of race
*/

#include "rpg.h"

static void display_win(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/you_win.png", NULL);
    sfSprite *sprite = get_sprite(texture);

    sfSprite_setPosition(sprite, get_position(600, 150));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

static void display_lose(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/you_lose.png", NULL);
    sfSprite *sprite = get_sprite(texture);

    sfSprite_setPosition(sprite, get_position(600, 150));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

static void detect_return_click(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed &&
    game->event.mouseButton.x > 880 && game->event.mouseButton.x < 1050
    && game->event.mouseButton.y > 660 && game->event.mouseButton.y < 720) {
        game->scene = 2;
        game->time = 5;
        sfSprite_setPosition(game->backgrounds[3].sprite,
        get_position(-800, -1700));
        sfSprite_setPosition(game->backgrounds[9].sprite,
        get_position(-800, -1700));
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        sfSprite_setPosition(game->current_car.sprite, get_position(950, 700));
        sfMusic_destroy(game->race.music.music);
        game->event.type = sfEvtMouseButtonReleased;
        if (game->speedlist[game->race.boss].eliminated == 1 &&
        game->race.boss == 6) {
            game->scene = 10;
            set_anim_race(game);
        }
    }
}

void display_end_menu(int is_win, int score, sfRenderWindow *win,
game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/end_menu.png", NULL);
    sfSprite *sprite = get_sprite(texture);

    sfSprite_setPosition(sprite, get_position(600, 150));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    if (is_win == 1)
        display_win(win);
    else
        display_lose(win);
    detect_return_click(game);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
