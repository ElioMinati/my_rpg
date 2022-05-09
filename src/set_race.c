/*
** EPITECH PROJECT, 2022
** set_race.c
** File description:
** functions used to set the race
*/

#include "rpg.h"

static void set_race_variables(game_t *game)
{
    game->race.race_has_started = 0;
    sfClock_restart(game->race.race_clock.clock);
    game->race.distance = 0;
    game->race.enemy_distance = 0;
    game->current_car.gear = 1;
    game->race.gear_up_speed = 0;
    game->race.time_since_max_rev = 0;
    game->race.is_max_rev = 0;
    game->race.shift_time = 0;
    game->race.current_vel = 0;
    game->race.enemy_vel = 0;
    game->race.init_hp = game->current_car.horse_power;
    game->race.boss = -1;
    game->race.pitch = 1;
    game->race.pitch_incr = 0.0001;
}

char *get_normal_music(char **songs)
{
    return songs[4 + rand() % 4];
}

void set_race(game_t *game)
{
    sfSprite_setRotation(game->current_car.sprite, 0);
    sfSprite_setPosition(game->current_car.sprite, get_position(350, 950));
    sfSprite_setScale(game->current_car.sprite, get_position(1.2, 1.2));
    sfSprite_setPosition(game->parallax[0].sprite,
    get_position(0, 600 - 20));
    sfSprite_setScale(game->parallax[0].sprite, get_position(8, 8));
    get_random_enemy(game, game->cars);
    sfSprite_setPosition(game->enemy_car.sprite, get_position(300, 780));
    sfSprite_setScale(game->enemy_car.sprite, get_position(1.2, 1.2));
    set_race_variables(game);
    create_music(get_normal_music(game->songs), &game->race.music);

}
