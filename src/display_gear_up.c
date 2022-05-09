/*
** EPITECH PROJECT, 2022
** display_gear_up
** File description:
** function used to display the gear up on screen
*/

#include "rpg.h"
#include "my.h"

void display_key_to_press(game_t *game, sfRenderWindow *win)
{
    char *c = malloc(sizeof(char) * 2);
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(
    game->race.race_clock.clock));
    char *text = "PRESS ";

    c[0] = game->key + 97;
    c[1] = '\0';
    text = my_strcat(text, c);
    if ((int)(seconds / 0.5) % 2 == 1)
        display_text(get_position(800, 450), text, 50, win);
    else
        display_green_text(get_position(800, 450), text, 50, win);
}

void display_gear_up(game_t *game, sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/shift_up.png", NULL);
    sfSprite *sprite = get_sprite(texture);
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(
    game->race.race_clock.clock));

    sfSprite_setPosition(sprite, get_position(200, 200));
    if ((int)(seconds / 0.5) % 2 == 1)
        display_text(get_position(400, 200), "SHIFT UP", 220, win);
    else
        display_green_text(get_position(400, 200), "SHIFT UP", 220, win);
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfSprite_setPosition(sprite, get_position(1400, 200));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    display_key_to_press(game, win);
}