/*
** EPITECH PROJECT, 2022
** display_text_bubbles.c
** File description:
** functions used to display the animation text bubbles
*/

#include "rpg.h"

void display_bubble(sfRenderWindow *win, char *filename)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = get_sprite(texture);

    sfSprite_setPosition(sprite, get_position(1100, 740));
    sfSprite_setScale(sprite, get_position(0.7, 0.7));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void display_text_bubbles(sfRenderWindow *win, game_t *game,
float seconds)
{
    if (seconds > 2 && game->event.type == sfEvtMouseButtonPressed) {
        game->event.type = sfEvtMouseButtonReleased;
        game->nb_bubble += 1;
    }
    if (seconds > 2 && game->nb_bubble == 0)
        display_bubble(win, "files/misc/bubble1.png");
    if (game->nb_bubble == 1)
        display_bubble(win, "files/misc/bubble2.png");
    if (game->nb_bubble == 2)
        display_bubble(win, "files/misc/bubble3.png");
    if (game->nb_bubble == 3)
        display_bubble(win, "files/misc/bubble4.png");
    if (game->nb_bubble == 4)
        display_bubble(win, "files/misc/bubble5.png");
    if (game->nb_bubble == 5) {
        game->race.race_clock.clock = sfClock_create();
        game->nb_bubble += 1;
    }
}
