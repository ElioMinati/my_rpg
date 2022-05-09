/*
** EPITECH PROJECT, 2022
** init_particles
** File description:
** functions used to initialize particles
*/

#include "rpg.h"

sfColor get_random_color(int x, int y)
{
    int randint = rand();

    if (((randint % 5) + x) > 6 &&
    ((y + rand() % 2) < 3 || (y + rand() % 2) > 0))
        return sfRed;
    else if (((randint % 5) + x) > 4 &&
    ((y + rand() % 2) < 3 || (y + rand() % 2) > 0))
        return sfColor_fromRGB(255, 165, 0);
    else
        return sfYellow;

}

void add_square_pixel(sfVertexArray *arr, sfColor color, sfVector2f offset,
sfVector2f actual_pos)
{
    int x = 0;
    int y = 0;
    sfVertex vertex;

    if (((offset.y > 5 || offset.y < 5) && offset.x < (3 + rand() % 6))
    || (offset.y != 5 && offset.x < (3 + rand() % 6)))
        vertex.color = sfTransparent;
    else
        vertex.color = color;
    vertex.texCoords = get_position(offset.x, offset.y);
    for (int i = 0; i < 25; ++i) {
        vertex.position = get_position(actual_pos.x +
        offset.x + x / 5, actual_pos.y + offset.y + y);
        sfVertexArray_append(arr, vertex);
        y = (y + 1) % 5;
        x += 1;
    }
}

void init_particles(game_t *game)
{
    int x = 0;
    int y = 0;
    sfVertex vertex;
    sfVector2f pos = sfSprite_getPosition(game->current_car.sprite);
    sfVector2f origin = sfSprite_getOrigin(game->current_car.sprite);
    sfVector2f actual_pos = {pos.x - origin.x - 70, pos.y + 5};

    game->particles.particles = sfVertexArray_create();
    for (int i = 0; i < 18; ++i) {
        add_square_pixel(game->particles.particles,
        get_random_color((x / 3), y), get_position(
        (x / 3) * 5 + (rand() % 2), y * 5), actual_pos);
        y = (y + 1) % 3;
        x += 1;
    }
    sfClock_restart(game->particles.clock.clock);
}
