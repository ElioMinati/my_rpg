/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** init3
*/

#include "rpg.h"
#include "my.h"

void init_rules(game_t *game)
{
    int fd = open("info", O_RDONLY);

    game->rules = malloc(381 + sizeof(char));
    read(fd, game->rules, 381);
    close(fd);
    game->rules[381] = '\0';
    game->xp = malloc(sizeof(char) * 100);
    game->xp = my_itoa(10000);
    game->error_clock.error = 0;
    game->error_clock.clock = sfClock_create();
    game->movement_clock.clock = sfClock_create();
    game->race.music.has_played = 0;
    game->current_car.is_moving = 0;
    game->time = 5;
    init_pnj(game);
    init_musics(game);
}

void init_xp(game_t *game)
{
    game->main_buttons[12].texture = sfTexture_createFromFile
    ("files/misc/xp.png", NULL);
    game->main_buttons[12].sprite = get_sprite(game->main_buttons[12].texture);
    sfSprite_setScale(game->main_buttons[12].sprite, get_position(0.85, 0.85));
    sfSprite_setPosition(game->main_buttons[12].sprite,
    get_position(270, 0));
    sfSprite_setPosition(game->backgrounds[10].sprite, get_position(500, 200));
    game->level = 0;
    game->race.race_clock.clock = sfClock_create();
}

void init_return(game_t *game)
{
    game->main_buttons[7].texture = sfTexture_createFromFile
    ("files/buttons/return.png", NULL);
    game->main_buttons[7].sprite = get_sprite(game->main_buttons[7].texture);
    sfSprite_setScale(game->main_buttons[7].sprite, get_position(2, 2));
    sfSprite_setPosition(game->main_buttons[7].sprite,
    get_position(10, 950));
    sfSprite_setTexture(game->main_buttons[7].sprite,
    game->main_buttons[7].texture, sfTrue);
    sfSprite_setTextureRect(game->main_buttons[7].sprite,
    get_rect(0, 0, 48, 35));
    game->main_buttons[10].texture = sfTexture_createFromFile
    ("files/buttons/return.png", NULL);
    game->main_buttons[10].sprite = get_sprite(game->main_buttons[10].texture);
    sfSprite_setScale(game->main_buttons[10].sprite, get_position(2, 2));
    sfSprite_setPosition(game->main_buttons[10].sprite,
    get_position(1815, 10));
    sfSprite_setTexture(game->main_buttons[10].sprite,
    game->main_buttons[10].texture, sfTrue);
    sfSprite_setTextureRect(game->main_buttons[10].sprite,
    get_rect(0, 0, 48, 35));
}

void init_pause(game_t *game)
{
    game->main_buttons[13].texture = sfTexture_createFromFile
    ("files/buttons/close.png", NULL);
    game->main_buttons[13].sprite = get_sprite(game->main_buttons[13].texture);
    sfSprite_setPosition(game->main_buttons[13].sprite,
    get_position(1200, 250));
    sfSprite_setTextureRect(game->main_buttons[13].sprite,
    get_rect(0, 0, 120, 84));
    game->main_buttons[14].texture = sfTexture_createFromFile
    ("files/buttons/button_pause.png", NULL);
    game->main_buttons[14].sprite = get_sprite(game->main_buttons[14].texture);
    sfSprite_setPosition(game->main_buttons[14].sprite,
    get_position(20, 20));
    sfSprite_setTextureRect(game->main_buttons[14].sprite,
    get_rect(0, 0, 28, 28));
    sfSprite_setScale(game->main_buttons[14].sprite, get_position(3, 3));
}
