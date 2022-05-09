/*
** EPITECH PROJECT, 2022
** challenge.c
** File description:
** fonctions used for the challenges
*/

#include "rpg.h"

static void set_boss_music(game_t *game)
{
    if (game->race.boss == 6)
        create_music(game->songs[3], &game->race.music);
    if (game->race.boss == 5)
        create_music(game->songs[1], &game->race.music);
    if (game->race.boss == 4)
        create_music(game->songs[2], &game->race.music);
    if (game->race.boss == 3)
        create_music(game->songs[0], &game->race.music);
    if (game->race.boss < 3)
        create_music(get_normal_music(game->songs), &game->race.music);
}

void set_boss_car(game_t *game, car_t car)
{
    game->enemy_car.max_speed = car.max_speed;
    game->enemy_car.horse_power = car.horse_power;
    game->enemy_car.texture = sfSprite_getTexture(car.sprite);
    game->enemy_car.sprite = get_sprite(game->enemy_car.texture);
    game->enemy_car.anim = sfClock_create();
    game->enemy_car.rect_offset = car.rect_offset;
    game->enemy_car.rect_max = car.rect_max;
    sfSprite_setPosition(game->enemy_car.sprite, get_position(960, 590));
    sfSprite_setOrigin(game->enemy_car.sprite, car.offset);
    sfSprite_setTextureRect(game->enemy_car.sprite,
    sfSprite_getTextureRect(car.sprite));
    sfSprite_setScale(game->enemy_car.sprite, get_position(0.7, 0.7));
}

static void set_boss_race(game_t *game, car_t boss, int i)
{
    sfSprite_setRotation(game->current_car.sprite, 0);
    sfSprite_setPosition(game->current_car.sprite, get_position(350, 950));
    sfSprite_setScale(game->current_car.sprite, get_position(1.2, 1.2));
    sfSprite_setPosition(game->parallax[0].sprite,
    get_position(0, 600 - 20));
    sfSprite_setScale(game->parallax[0].sprite, get_position(8, 8));
    set_boss_car(game, boss);
    sfSprite_setPosition(game->enemy_car.sprite, get_position(300, 780));
    sfSprite_setScale(game->enemy_car.sprite, get_position(1.2, 1.2));
    game->race.race_has_started = 0; game->race.anim = 0;
    game->race.distance = 0; game->race.enemy_distance = 0;
    game->current_car.gear = 1; game->race.gear_up_speed = 0;
    game->race.time_since_max_rev = 0; game->race.is_max_rev = 0;
    game->race.shift_time = 0;
    game->race.current_vel = 0;
    game->race.enemy_vel = 0;
    game->race.init_hp = game->current_car.horse_power;
    game->race.boss = i;
    game->race.pitch = 1;
    game->race.pitch_incr = 0.0001;
}

void init_challenge(game_t *game, sfRenderWindow *win, int i)
{
    sfSprite_setTextureRect(game->main_buttons[9].sprite,
    get_rect(43, 0, 177, 43));
    game->scene = 5;
    set_boss_race(game, game->speedlist[i], i);
    set_boss_music(game);
}
