/*
** EPITECH PROJECT, 2022
** beginning_anim
** File description:
** functions used for the beginning animation
*/

#include "rpg.h"

void set_anim_race(game_t *game)
{
    sfSprite_setRotation(game->current_car.sprite, 0);
    sfSprite_setPosition(game->current_car.sprite, get_position(350, 950));
    sfSprite_setScale(game->current_car.sprite, get_position(1.2, 1.2));
    sfSprite_setPosition(game->parallax[0].sprite,
    get_position(0, 600 - 20));
    sfSprite_setScale(game->parallax[0].sprite, get_position(8, 8));
    set_enemy_car(game, game->speedlist[6]);
    sfSprite_setPosition(game->enemy_car.sprite, get_position(300, 780));
    sfSprite_setScale(game->enemy_car.sprite, get_position(1.2, 1.2));
    if (game->scene == 10)
        sfSprite_move(game->enemy_car.sprite, get_position(700, 0));
    game->race.race_has_started = 0;
    game->race.race_clock.clock = sfClock_create();
    game->current_car.gear = 1;
    game->race.current_vel = 0;
    game->race.enemy_vel = 0;
    game->race.init_hp = game->current_car.horse_power;
    game->enemy_car.horse_power = game->current_car.horse_power;
    game->race.fader = 1;
    game->nb_bubble = 0;
}

void move_anim_parallax(game_t *game, sfRenderWindow *win)
{
    sfVector2f bg_pos = sfSprite_getPosition(game->parallax[0].sprite);

    move_texture_rect(game->current_car.sprite, game->current_car.rect_offset,
    game->current_car.rect_max, game->current_car.anim);
    move_texture_rect(game->enemy_car.sprite, game->enemy_car.rect_offset,
    game->enemy_car.rect_max, game->enemy_car.anim);
    if (bg_pos.x <= -((768 / 3) * 8))
        sfSprite_setPosition(game->parallax[0].sprite,
        get_position(0, 600 - 20));
    else {
        sfSprite_move(game->parallax[0].sprite,
        get_position(-20, 0));
    }
}

void display_adrian(sfRenderWindow *win)
{
    sfTexture *texture = sfTexture_createFromFile(
    "files/misc/adrian.png", NULL);
    sfSprite *sprite = get_sprite(texture);

    sfSprite_setPosition(sprite, get_position(850, 690));
    sfSprite_setScale(sprite, get_position(0.7, 0.7));
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void display_anim(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    sfRenderWindow_drawSprite(window, game->parallax[1].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->parallax[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->enemy_car.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->current_car.sprite, NULL);
    if (is_button_pressed(game, game->main_buttons[11])) {
        sfSprite_setTextureRect(game->main_buttons[11].sprite,
        get_rect(43, 0, 85, 43));
        game->scene = 2;
        sfSprite_setPosition(game->current_car.sprite, get_position(960, 590));
        sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
        init_particles(game);
    } else
        sfSprite_setTextureRect(game->main_buttons[11].sprite,
        get_rect(0, 0, 85, 43));
    move_anim_parallax(game, window); display_bubbles(game, window);
    sfRenderWindow_drawSprite(window, game->main_buttons[11].sprite, NULL);
    if (is_button_hovered(window, game, game->main_buttons[11]))
        draw_rect(sfSprite_getPosition(game->main_buttons[11].sprite),
        get_position(85, 42), 100, window);
}
