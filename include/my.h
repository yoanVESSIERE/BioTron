/*
** EPITECH PROJECT, 2019
** include/../include/my.h
** File description:
** 
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Color.h>
#define S one_by_one

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

typedef struct perso_s {
    char *nom;
    int sexe;
    char *weapon;
    int vie;
    int vie_max;
    char *statut;
    int gold;
    char **spell;
    char **inv;
    int *tab_inv;
    int expe;
    int level;
    int exp_need;
    int ame;
} perso_t;

typedef struct monster_s {
    char *nom;
    int vie;
    char *statut;
    char *loot;
    int gold_to_give;
    int exp_to_give;
    int damage;
} monster_t;

typedef struct statis_s {
    int force;
    int intelligence;
    int defense;
} statis_t;

typedef struct weap_s {
    int force;
    int intelligence;
    int defense;
} weap_t;

typedef struct data_s {
    perso_t player;
    statis_t stat;
    weap_t weapstat;
    monster_t monster;
} data_t;

perso_t struct_player(perso_t player);

statis_t struct_stat(statis_t stat);

weap_t struct_weap(weap_t weapstat);

monster_t struct_slime(monster_t monster);

int damage(data_t datap);

void eval_spell(char *buff, data_t *datap);

int damage(data_t datap);

char *choice(int nb, char *buff, size_t size, ...);

void combat_slime(data_t datap, char *buff, sfMusic *music[20]);

void fin_combat(char *buff, data_t datap, sfMusic *music[20]);

void boucle(char *buff, data_t datap, sfMusic *music[20]);

int random_number(int min_num, int max_num);

int quet(data_t *datap, char *buff);

void one_by_one(char *str);