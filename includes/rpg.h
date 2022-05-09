/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef RPG_H__
    #define RPG_H__

typedef enum {
    START,
    QUIT,
    RACE,
    LOGO,
    INFO
} btnType;

typedef enum {
    TURBO,
    AIR_FILTER,
    RADIATOR,
    MAP,
    PISTON
} partType;

typedef struct pnj_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *text;
    sfTexture *texttexture;
} pnj_t;

typedef struct items_s {
    int pos;
    int page;
    int psi;
    char *name;
    float gain;
    sfSprite *sprite;
    sfTexture *texture;
    partType type;
} item_t;

typedef struct music_s {
    sfMusic *music;
    int has_played;
} music_t;

typedef struct quest_s {
    char *text;
} quest_t;

typedef struct background_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} background_t;

typedef struct userdata_s {
    char *name;
    int age;
    int money;
    char *car;
} __attribute__((packed)) userdata_t;

typedef struct car_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f offset;
    sfClock *anim;
    item_t *items;
    int nb_items;
    int rect_offset;
    int rect_max;
    int cooldown;
    int is_moving;
    int speed;
    int price;
    int nb_cars;
    int horse_power;
    int turbo;
    int zero_one_hundred;
    int zero_one_hundred_after_comma;
    int max_speed;
    int selected;
    int eliminated;
    int gear;
    int max_gear;
    int garage_pos;
    char *name;
    int item_selected;
} car_t;

typedef struct play_music_s {
    sfMusic *music;
    int music_index;
} play_music_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    btnType type;
    int is_toggled;
    int nb_buttons;
    int is_pressed;
    int selected;
} button_t;

typedef struct rpg_clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
    int error;
} rpg_clock_t;

typedef struct inventory_s {
    sfSprite *button_sprite;
    sfSprite *sprite;
    sfTexture *button_texture;
    sfTexture *texture;
    sfIntRect rect;
    int status;
    int selected;
} inventory_t;

typedef struct particles_s {
    sfVertexArray *particles;
    rpg_clock_t clock;
} particles_t;

typedef struct race_s {
    int race_has_started;
    int distance;
    int enemy_distance;
    int is_win;
    int score;
    int gear_up_speed;
    float time_since_max_rev;
    int is_max_rev;
    int current_vel;
    int enemy_vel;
    float shift_time;
    int init_hp;
    int fader;
    rpg_clock_t race_clock;
    rpg_clock_t gear_clock;
    music_t stutu;
    music_t music;
    int boss;
    float pitch;
    float pitch_incr;
    int anim;
    char *name;
} race_t;

typedef struct game_s {
    int key;
    int scene;
    int pause;
    inventory_t inventory;
    item_t *items;
    button_t *main_buttons;
    button_t *dealership_buttons;
    button_t *parts;
    button_t *inv_buttons;
    background_t *backgrounds;
    background_t *parallax;
    pnj_t *pnj;
    userdata_t user;
    sfRectangleShape **colision_rect;
    car_t *speedlist;
    car_t *cars;
    car_t current_car;
    car_t enemy_car;
    car_t *garage;
    quest_t *quest;
    play_music_t music;
    race_t race;
    sfEvent event;
    rpg_clock_t clock;
    rpg_clock_t speedrun_clock;
    rpg_clock_t animation_clock;
    rpg_clock_t error_clock;
    rpg_clock_t movement_clock;
    particles_t particles;
    sfRenderWindow *win;
    int leandre;
    int time;
    char **songs;
    int races_done;
    int races_win;
    int is_config;
    int nb_bubble;
    int money;
    int money_spend;
    int current_quest;
    int car_is_bought;
    char *reward;
    char *xp;
    int get_xp;
    int level;
    int inv_page;
    int nb_items;
    char *rules;
} game_t;

// display_basics.c
void display_help(void);
void manage_mouse_click(game_t *game);

// sound.c
void music_menu(game_t *game);
void manage_end_music(sfRenderWindow *window, game_t *game);
void music_endgame(sfRenderWindow *window, game_t *game, char *path);
void music_ingame(sfRenderWindow *window, game_t *game, char *path);
void music(sfRenderWindow *window, game_t *game);

// events_handeling.c
void inputhandler(sfRenderWindow *window, game_t *game);
void move_line_map(game_t *game, sfVector2f pos, sfVector2f car_pos);

// rpg.c
void my_rpg(sfRenderWindow *window, game_t *game);

// destoyer.c
void destroyer(sfRenderWindow *window, game_t *game);

// change_scene.c
void choose(sfRenderWindow *window, game_t *game);

// init.c
void rpg_init(game_t *game);
void init_sprite(game_t *game);

// get.c
sfVector2f get_position(float x, float y);
sfSprite *get_sprite(sfTexture* texture);
sfIntRect get_rect(int top, int left, int width, int height);
sfSprite *get_sprite2(sfTexture* texture, game_t *game);

// game.c
void display_game(sfRenderWindow *window, game_t *game);
void display_dealership(sfRenderWindow *win, game_t *game);
void display_garage(sfRenderWindow *window, game_t *game);
void display_inventory(sfRenderWindow *window, game_t *game);
void display_pause_menu(sfRenderWindow *window, game_t *game);
void display_player_stats(sfRenderWindow *window, game_t *game);

// start.c
void display_start(sfRenderWindow *window, game_t *game);

// choose_car
void display_car_choice(sfRenderWindow *window, game_t *game);

// window_basics.c
void display_window(sfRenderWindow *window);
sfRenderWindow *create_renderwindow(unsigned int x, unsigned int y
                                            , unsigned int bpp, char *title);

// button_start.c
void init_button_start(game_t *game);
void manage_start_button(sfRenderWindow *window, game_t *game);
void init_button_quit(game_t *game);
void manage_quit_button(sfRenderWindow *window, game_t *game);
void manage_end_button(sfRenderWindow *window, game_t *game);
void manage_start_buttonb(sfRenderWindow *window, game_t *game);

// text.c
void display_red_text(sfVector2f pos, char *str, int size,
sfRenderWindow *win);
void display_text(sfVector2f pos, char *str, int size, sfRenderWindow *win);
void draw_rect(sfVector2f pos, sfVector2f size, int opacity,
sfRenderWindow *win);
void colision(game_t *game, sfRenderWindow *window);
int colision_is_touch(game_t *game, sfVector2f pos, sfVector2f car_pos);
void draw_green_border_rect(sfVector2f pos, sfVector2f size, int opacity,
sfRenderWindow *win);
void display_green_text(sfVector2f pos, char *str, int size,
sfRenderWindow *win);
void speedrun_text(sfRenderWindow *window, char *string, int x, int y);

// config.c
void save_rpg_config(sfRenderWindow *window, game_t *game, char *file);

//init_map.c
void init_map(game_t *game);

// end.c
void display_end(sfRenderWindow *window, game_t *game);
void display_fade(sfRenderWindow *window, game_t *game);

// get_config.c
void get_config(game_t *game, char *arg);

// analyse_events.c
void analyse_events(sfRenderWindow *win, game_t *game);

// car_handling.c
void set_current_car(game_t *game, car_t car, int pos);
void put_car_in_garage(game_t *game, car_t car);
void transfer_car_to_garage(game_t *game, car_t *garage, car_t car, int i);

// move_texture_rect.c
void move_texture_rect(sfSprite *sprite, int offset, int max, sfClock *clock);

// create_starter_cars.c
void create_205(car_t *cars, int index);
void create_206(car_t *cars, int index);
void create_civic(car_t *cars, int index);

// init_cars.c
void create_cars(game_t *game);
void create_garage_button(button_t *buttons);

// detect_button_pressing.c
int is_button_pressed(game_t *game, button_t button);
int is_button_hovered(sfRenderWindow *win, game_t *game, button_t button);

// dealership_events.c
void handle_dealership_events(game_t *game, sfRenderWindow *win);
int get_dealership_car(car_t *cars);
void set_dealership_cars(game_t *game);

// init2.c
void init_inventory(game_t *game);
void init_race(game_t *game);
void init_logo(game_t *game);

// check_game_pos.c
void check_binv_pos(sfRenderWindow *window, game_t *game);
void check_binv_mouse(sfRenderWindow *window, game_t *game);

// button_start2.c
void manage_start_buttonb(sfRenderWindow *window, game_t *game);
void manage_quit_buttonb(sfRenderWindow *window, game_t *game);

// inv_handling.c
void inv_handling(sfRenderWindow *window, game_t *game);
void inv_event(sfRenderWindow *window, game_t *game);
void display_inv_info_first_line(sfRenderWindow *win, game_t *game);

// analyse_events2.c
void detect_car_pressed(game_t *game, sfVector2i mouse);
void analyse_garage_events(game_t *game, sfVector2i mouse, sfRenderWindow *win);

//race.c
void display_race(sfRenderWindow *window, game_t *game);
void set_race(game_t *game);
void set_enemy_car(game_t *game, car_t car);

//display_garage_cars.c
void display_selected_car_item(game_t *game, sfRenderWindow *win);
void display_garage_cars(car_t *garage, sfRenderWindow *win);

//init_boss_cars.c
void create_boss_skyline(car_t *cars, int index);
void create_boss_civic(car_t *cars, int index);
void create_boss_bttf(car_t *cars, int index);
void create_boss_challenger(car_t *cars, int index);
void create_boss_r35(car_t *cars, int index);

//init_more_boss_cars.c
void create_boss_r8(car_t *cars, int index);
void create_boss_lfa(car_t *cars, int index);

//analyse_speedlist.c
void analyse_speedlist_events(game_t *game, sfVector2i mouse,
sfRenderWindow *win);

//race_handling.c
void handle_race_start(game_t *game, sfRenderWindow *win);
void display_start_countdown(int number, sfRenderWindow *win);

//race_end.c
void display_end_menu(int is_win, int score, sfRenderWindow *win,
game_t *game);

//init_parts_shop.c
void init_parts_shop(game_t *game);

//display_parts_shop.c
void display_part_shop(sfRenderWindow *window, game_t *game);
void draw_selected(sfRenderWindow *win, game_t *game);

//analyse_part_shop_events.c
void analyse_shop_events(sfRenderWindow *window, game_t *game);
void move_purchase_rect(game_t *game);

//display_money.c
void display_money(sfRenderWindow *win, game_t *game);

//display_gear_up.c
void display_gear_up(game_t *game, sfRenderWindow *win);

//manage_return.c
void manage_return(sfRenderWindow *window, game_t *game);

//garage_events.c
void detect_garage_car_pressing(game_t *game);

//rules_scene.c
void display_rules(sfRenderWindow *window, game_t *game);
void manage_info_button(sfRenderWindow *window, game_t *game);

//init_return_and_so.c
void init_rules(game_t *game);
void init_return(game_t *game);
void init_xp(game_t *game);
void init_pause(game_t *game);

//mathis.c
void manage_mathis(sfRenderWindow *window, game_t *game);

// item.c
void change_page(sfRenderWindow *win, game_t *game);
void display_item(sfRenderWindow *win, game_t *game);

//init_inv_buttons.c
void init_inv_buttons(game_t *game);

//analyse_purchase_item.c
void check_selected(game_t *game);

//beginning_anim.c
void display_anim(sfRenderWindow *window, game_t *game);
void set_anim_race(game_t *game);
void display_adrian(sfRenderWindow *win);

//display_text_bubbles.c
void display_text_bubbles(sfRenderWindow *win, game_t *game,
float seconds);
void display_bubble(sfRenderWindow *win, char *filename);

//init_parts.c
void init_more_air_filters(game_t *game);

//display_parts.c
void display_air_filters(sfRenderWindow *win, game_t *game);
void display_radiators(sfRenderWindow *win, game_t *game);

//display_engine_parts.c
void display_pistons(sfRenderWindow *win, game_t *game);
void display_cartos(sfRenderWindow *win, game_t *game);

//init_engine_parts.c
void init_pistons(game_t *game);

//analyse_engine_shop_events.c
void analyse_piston_events(sfRenderWindow *window, game_t *game);

//music.c
void create_music(char *filename, music_t *music);
void play_music(sfMusic *music);

//init_hard_cars.c
void create_mojang(car_t *cars, int index);
void create_rx7(car_t *cars, int index);
void create_z76(car_t *cars, int index);
void create_supra(car_t *cars, int index);
void create_silvia(car_t *cars, int index);

//init_intermediate_cars.c
void create_cooper(car_t *cars, int index);
void create_cobalt(car_t *cars, int index);
void create_camaro_ss(car_t *cars, int index);
void create_bel_air(car_t *cars, int index);

//init_sports_cars.c
void create_850r(car_t *cars, int index);
void create_350z(car_t *cars, int index);
void create_180sx(car_t *cars, int index);
void create_crx(car_t *cars, int index);

//init_beginner_cars.c
void create_is200(car_t *cars, int index);
void create_golf(car_t *cars, int index);
void create_e92(car_t *cars, int index);
void create_e36(car_t *cars, int index);

//init_oponents.c
void init_all_cars(game_t *game);

//analyse_purchase_item_2.c
void check_selectedf(game_t *game);

//analyse_purchase_item_3.c
void check_selectedk(game_t *game);

//analyse_purchase_item_4.c
void check_selectedp(game_t *game);

//challenge.c
void init_challenge(game_t *game, sfRenderWindow *win, int i);

//display_start_animation.c
void do_fader(game_t *game, sfRenderWindow *win);
void display_bubbles(game_t *game, sfRenderWindow *window);

//display_alt_inv.c
void display_alt_inv(sfRenderWindow *win);

//display_selected.c
void select_item(game_t *game, int nb);
void display_selected_item(game_t *game, sfRenderWindow *win);
void select_car_item(game_t *game, int nb);

//analyse_item_pressing.c
void analyse_item_pressing(game_t *game, sfRenderWindow *win);

//unequip.c
void unequip(int index, game_t *game, sfRenderWindow *window);

//remove_items.c
void remove_item(item_t *new_items, game_t *game, int j, int i);
void remove_item_garage(item_t *new_items, game_t *game, int j, int i);
void remove_item_first(item_t *new_items, game_t *game, int j, int i);

//tune_car.c
void detune(game_t *game, item_t item);
void tune(game_t *game, item_t item);

//quest.c
void init_quests(game_t *game);
void choose_quest(sfRenderWindow *window, game_t *game);

//display_quests.c
void display_quest_one(sfRenderWindow *window, game_t *game);
void display_quest_two(sfRenderWindow *window, game_t *game);
void display_quest_three(sfRenderWindow *window, game_t *game);
void display_quest_four(sfRenderWindow *window, game_t *game);
void display_quest_five(sfRenderWindow *window, game_t *game);

//rewards.c
void display_rewards(game_t *game, sfRenderWindow *win);
void get_reward_win(game_t *game);
void get_reward_lose(game_t *game);

//handle_boss_anim.c
void handle_boss_anim(sfRenderWindow *win, game_t *game);

//equip.c
void equip(int index, game_t *game, sfRenderWindow *window);

//car_inv_handling.c
void display_car_inv_info_first_line(sfRenderWindow *win, game_t *game);

//display_selected.c
void analyse_equip_events(game_t *game, sfRenderWindow *win);
void analyse_unequip_events(game_t *game, sfRenderWindow *win);

//particle_effects.c
void display_particles(sfRenderWindow *win, game_t *game);

//init_particles.c
void init_particles(game_t *game);

//do_race.c
void handle_during_race(game_t *game, sfRenderWindow *window);
void move_race_objects(game_t *game, sfVector2f bg_pos);
void do_gear_up(game_t *game, sfRenderWindow *win);

//set_race.c
void set_race(game_t *game);
void get_random_enemy(game_t *game, car_t *cars);

//display_xp.c
void display_xp(game_t *game, sfRenderWindow *win);

//error.c
void display_error_message(sfVector2f pos, char *str,
game_t *game, sfRenderWindow *win);
void handle_car_buy(game_t *game, sfRenderWindow *win);
void check_money(game_t *game, int selected, int price, int xp);

//display_inventory.c
void display_inventory(sfRenderWindow *window, game_t *game);

//display_dealership.c
void display_dealership(sfRenderWindow *win, game_t *game);

//handle_derkha.c
void init_pnj(game_t *game);
void handle_leandre(sfRenderWindow *window, game_t *game);

//collision.c
void colision(game_t *game, sfRenderWindow *window);
int colision_is_touch(game_t *game, sfVector2f pos, sfVector2f car_pos);

//analyse_buttons.c
void detect_garage_button(sfRenderWindow *win, game_t *game);
void move_garage_cars(game_t *game);

//display_end_anim.c
void display_end_anim(sfRenderWindow *win, game_t *game);

//analyse_pause_events.c
void analyse_pause_events(game_t *game, sfRenderWindow *win);

//init_musics.c
void init_musics(game_t *game);
char *get_normal_music(char **songs);

//handle_move_right.c
void handle_move_right(game_t *game, sfVector2f pos,
sfVector2f car_pos);

//draw_rect.c
sfRectangleShape *return_rect(sfVector2f pos, sfVector2f size, int opacity,
sfRenderWindow *win);
void draw_rect(sfVector2f pos, sfVector2f size, int opacity,
sfRenderWindow *win);
void draw_green_border_rect(sfVector2f pos, sfVector2f size, int opacity,
sfRenderWindow *win);

//init_map.c
void init_more_backgrounds(game_t *game);

//choose_time.c
void choose_time(sfRenderWindow *win, game_t *game);

#endif
