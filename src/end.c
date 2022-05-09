/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** end
*/

#include "rpg.h"

void do_end_music(sfRenderWindow *window, game_t *game)
{
    game->clock.time = sfClock_getElapsedTime(game->clock.clock);
    game->clock.seconds = game->clock.time.microseconds / 1000000.0;
    if (game->clock.seconds >= 15)
        display_fade(window, game);
}

void display_credits(sfRenderWindow *window, game_t *game)
{
    int fd = open("credits", O_RDONLY);
    char *buffer = NULL;

    buffer = malloc(266 + sizeof(char));
    read(fd, buffer, 266);
    buffer[266] = '\0';
    close(fd);
    display_text(get_position(280, 100), buffer, 45, window);
}

void display_fade(sfRenderWindow *window, game_t *game)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, get_position(1920, 1080));
    sfRectangleShape_setPosition(rect, get_position(0, 0));
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, game->race.fader));
    if (game->race.fader <= 254)
        game->race.fader += 1;
    if (game->race.fader > 253)
        game->scene = 2;
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void display_end(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    sfRenderWindow_drawSprite(window, game->backgrounds[6].sprite, NULL);
    display_text(get_position(850, 50), "Credits", 75, window);
    display_credits(window, game);
    do_end_music(window, game);
}