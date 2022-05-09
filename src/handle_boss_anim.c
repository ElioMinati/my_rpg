/*
** EPITECH PROJECT, 2022
** handle_boss_anim.c
** File description:
** functions used to the beginning boss animation
*/

#include "rpg.h"
#include "my.h"

static void display_leandre(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/leandre.png", NULL);
    sfSprite *sprite = get_sprite(texture);
    sfTexture *derkha_tex = sfTexture_createFromFile(
    "files/misc/derkha.png", NULL);
    sfSprite *derkha = get_sprite(derkha_tex);

    sfSprite_setScale(derkha, get_position(0.4, 0.4));
    sfSprite_setPosition(derkha, get_position(1000, 650));
    sfSprite_setPosition(sprite, get_position(820, 500));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfRenderWindow_drawSprite(win, derkha, NULL);
    sfTexture_destroy(texture);
    sfTexture_destroy(derkha_tex);
    sfSprite_destroy(sprite);
    sfSprite_destroy(derkha);
}

static void handle_bubble_display(sfRenderWindow *win, game_t *game)
{
    if (game->race.anim == 0)
        display_bubble(win, "files/misc/bubble6.png");
    if (game->race.anim == 2)
        display_bubble(win, "files/misc/bubble7.png");
    if (game->race.anim == 3)
        display_bubble(win, "files/misc/bubble8.png");
    if (game->race.anim == 4)
        display_bubble(win, "files/misc/bubble9.png");
    if (game->race.anim == 5)
        display_bubble(win, "files/misc/bubble10.png");
    if (game->race.anim == 6) {
        display_text(get_position(1300, 750), "VS", 100, win);
        display_text(get_position(1600, 950), "MOI MONSIEUR", 40, win);
    }
}

static void detect_pressing_anim(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        ++game->race.anim;
        game->event.type = sfEvtMouseButtonReleased;
    }
    if (game->race.boss == 6 && game->race.anim == 1)
        ++game->race.anim;
}

void handle_boss_anim(sfRenderWindow *win, game_t *game)
{
    draw_rect(get_position(800, 650), get_position(1120, 500), 150, win);
    if (game->race.boss == 1) {
        display_leandre(win);
        display_text(get_position(1300, 750), "VS", 100, win);
        display_text(get_position(1600, 950), "MOI MONSIEUR", 40, win);
    } else if (game->race.boss == 6) {
        display_adrian(win);
        handle_bubble_display(win, game);
    } else {
        display_text(get_position(820, 670),
        game->speedlist[game->race.boss].name, 40, win);
        display_text(get_position(1300, 750), "VS", 100, win);
        display_text(get_position(1600, 950), "MOI MONSIEUR", 40, win);
    }
    detect_pressing_anim(game);
    if (game->race.anim == 7)
        game->race.anim = 1;
    if (game->race.anim == 1)
        game->race.race_clock.clock = sfClock_create();
}
