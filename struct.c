/*
** EPITECH PROJECT, 2019
** struct.c
** File description:
** 
*/
#include "my.h"

perso_t struct_player(perso_t player)
{
    player.nom = malloc(sizeof(char) * 500);
    player.vie_max = 20;
    player.sexe = 0;
    player.statut = malloc(sizeof(char) * 500);
    player.vie = 20;
    player.expe = 0;
    player.weapon = NULL;
    player.gold = 0;
    player.spell = malloc(sizeof(char *) * 500);
    for (int i = 0; i != 100; i++)
        player.spell[i] = malloc(sizeof(char) * 500);
    player.inv = malloc(sizeof(char *) * 500);
    for (int i = 0; i != 100; i++) {
        player.inv[i] = malloc(sizeof(char) * 500);
        player.inv[i] = NULL;
    }
    player.tab_inv = malloc(sizeof(int) * 100);
    player.level = 1;
    player.exp_need = 10;
    player.ame = 0;
    return (player);
}

statis_t struct_stat(statis_t stat)
{
    stat.force = 0;
    stat.intelligence = 0;
    stat.defense = 0;
    return (stat);
}

weap_t struct_weap(weap_t weapstat)
{
    weapstat.force = 0;
    weapstat.intelligence = 0;
    weapstat.defense = 0;
    return (weapstat);
}

monster_t struct_slime(monster_t monster)
{
    monster.vie = 15;
    monster.damage = 5;
    monster.nom = "Slime";
    monster.statut = NULL;
    monster.loot = "";
    monster.exp_to_give = 2;
    monster.gold_to_give = 10;
    return (monster);
}