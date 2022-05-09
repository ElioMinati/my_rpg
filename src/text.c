/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** text
*/

#include "rpg.h"

void display_text(sfVector2f pos, char *str, int size, sfRenderWindow *win)
{
    sfFont *font = sfFont_createFromFile("files/pixelfont.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, size);
    sfText_setOutlineThickness(text, 5);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void display_green_text(sfVector2f pos, char *str, int size,
sfRenderWindow *win)
{
    sfFont *font = sfFont_createFromFile("files/pixelfont.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setColor(text, sfGreen);
    sfText_setCharacterSize(text, size);
    sfText_setOutlineThickness(text, 5);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void display_red_text(sfVector2f pos, char *str, int size,
sfRenderWindow *win)
{
    sfFont *font = sfFont_createFromFile("files/pixelfont.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    sfText_setCharacterSize(text, size);
    sfText_setOutlineThickness(text, 5);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void speedrun_text(sfRenderWindow *window, char *string, int x, int y)
{
    display_text(get_position(x, y), string, 50, window);
}
