/*
** EPITECH PROJECT, 2022
** particles_effects
** File description:
** particle effects functions
*/

#include "rpg.h"

void display_particles(sfRenderWindow *win, game_t *game)
{
    game->particles.clock.seconds = sfTime_asSeconds(
    sfClock_getElapsedTime(game->particles.clock.clock));
    sfRenderWindow_drawVertexArray(win, game->particles.particles, NULL);

    if (game->particles.clock.seconds > 0.2) {
        sfVertexArray_destroy(game->particles.particles);
        init_particles(game);
    }
}
