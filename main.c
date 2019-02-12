/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Biotron
*/

/*
S("\n  _____\n");
S(" /  O__] \n");
S("/  ___] \n");
S("\\   \\  \n");
S(" |   | \n");
S(" |   | \n");
S(" /   /\n");
S(" \\   \\\n");
S(" /   /\n");
*/

#include "include/my.h"

void Se(char *str, float nb_seconds_btw_words, float nb_mseconds_btw_letter, char *color, char *state)
{
    char c;
    int j = 0;

    if (color == NULL)
        color = WHITE;
    if (state == NULL)
        state = WHITE;
    if (nb_mseconds_btw_letter == 0)
        nb_mseconds_btw_letter = 1;
    system("setxkbmap olpc");
    for (; str[j] != '\0'; j++) {
        if (str[j] == ' ') {
            my_putchar(' ');
            sleep(nb_seconds_btw_words);
        } else {
            my_putstr(state);
            my_putstr(color);
            my_putchar(str[j]);
            usleep(nb_mseconds_btw_letter);
        }
    }
    system("setxkbmap fr");
    my_putstr(HIDDEN);
    c = getchar();
    my_putstr(WHITE);
    my_putstr(STRONG);
}

void adventure(data_t datap, char *buff, sfMusic *music[20])
{
    size_t size = 100;
    int i = 0;

    S("\n\nUne force se ressens à l'extérieur mais tu n'arrive pas à savoir de quoi il s'agit\n");
    sleep(1);
    S("Que fais tu ?\n");
    buff = choice(2, buff, size, "-Je sors dehors {1}", "\n-Je vais manger un p'tit dej ! {2}");
    i = atoi(buff);
    if (i == 2) {
        S("Tu prend ton croissant, ton chocolat chaud et tes céréales (sans lait evidemment) **Défense +1**");
        datap.stat.defense += 1;
    }
    sleep(1);
    S("\n\nC'est parti, oublie pas ton arme par contre !\nQue prend tu ?\n");
    buff = choice(3, buff, size, "-Epée et bouclier de base {1}", "\n-Arc de base {2}", "\n-Livre de Sort basique {3}");
    if (atoi(buff) == 1) {
        datap.player.weapon = "Epée et bouclier de base";
        datap.weapstat.force += 10;
        datap.weapstat.intelligence += 3;
        datap.weapstat.defense += 4;
    }
    if (atoi(buff) == 2) {
        datap.player.weapon = "Arc de base";
        datap.weapstat.force += 5;
        datap.weapstat.intelligence += 4;
        datap.weapstat.defense += 3;
    }
    if (atoi(buff) == 3) {
        datap.player.weapon = "Livre de Sort basique";
        datap.weapstat.force += 3;
        datap.weapstat.intelligence += 10;
        datap.weapstat.defense += 1;
    }
    sleep(1);
    combat_slime(datap, buff, music);
}

void eval_choice_dodo(char *buff, data_t datap, sfMusic *music[20])
{
    int a = 1;
    size_t size = 500;

    for (; atoi(buff) == 1; a++) {
        S("\nTu décides de te rendormir parce que le sommeil bah c'est cool\n\n");
        S("Le lendemain tu te réveilles, que fais tu ?\n");
        buff = choice(2, buff, size, "-Je me rendors {1}", "\n-Je me lève {2}");
        if (a == 4) {
            S("Lorsque tu te réveilles, ton village est en feu, les monstres l'ont");
            S(" envahi car personne n'a pu les battre et tu meurs brulé...pfff la honte\n");
            exit(0);
        }
    }
    sleep(1);
    if (a == 1)
        S("\nTu as bien dormis et te sens en forme");
    else {
        S("\nTu as beaucoup dormis et tu sens en SUPER FORME **Force +1**");
        datap.stat.force += 1;
    }
    adventure(datap, buff, music);
}

void histoire(data_t datap, char *buff, size_t size, sfMusic *music[20])
{
    S("Parfait, maintenant prépare toi a être transporté dans un ");
    S("monde inconnu, et c'est à TOI de chosir ton destin !");
    sleep(5);
    system("clear");
    sleep(1);
    S("ZzZzZzZzZz....");
    sleep(1);
    S("zZzZ...zZ.z..");
    sleep(1);
    S("AAAAAHH...");
    sleep(1);
    S("\nTu te réveille en sursaut de ton lit, tu as fait un cauchemar mais tu ne te souviens de rien...");
    sleep(1);
    S("\nQue fait tu ?\n");
    buff = choice(2, buff, size, "-Je me rendors {1}", "\n-Je me lève {2}");
    eval_choice_dodo(buff, datap, music);
}

void init_music(sfMusic *music[20])
{
    music[0] = sfMusic_createFromFile("lib/song/Ambiance song/intro.wav");
    music[1] = sfMusic_createFromFile("lib/song/Battle song/The Last Encounter (90s RPG Version) Full Loop.wav");
    music[2] = sfMusic_createFromFile("lib/song/Ambiance song/mus_act1_spiritworld_intro_110bpm");
    music[3] = sfMusic_createFromFile("lib/song/Ambiance song/song.wav");
    music[4] = sfMusic_createFromFile("lib/song/Ambiance song/breakdown.wav");
}

int main(void)
{
    char *buff = NULL;
    size_t size = 200;
    perso_t player = {NULL, 0, NULL, 0, 0, NULL, 0, NULL, NULL, NULL, 0, 0, 0, 0};
    data_t datap;
    statis_t stat;
    weap_t weapstat;
    monster_t monster;
    sfMusic *music[20];
    my_putstr(STRONG);

    init_music(music);
    sfMusic_play(music[0]);
    sfMusic_setLoop(music[0], 1);
    weapstat = struct_weap(weapstat);
    player = struct_player(player);
    stat = struct_stat(stat);
    monster = struct_slime(monster);
    datap.player = player;
    datap.monster = monster;
    datap.stat = stat;
    datap.weapstat = weapstat;
    //regle();
    system("clear");
    sleep(1);
    Se("Salut toi,", 0, 50000, BLUE, UNDERLINE);
    sleep(1);
    Se("Ton aventure commence !!!", 0, 50000, BLUE, UNDERLINE);
    sleep(1);
    S("Mais avant tout, est tu:\n");
    buff = choice(2, buff, size, "-Un Homme {1}\n", "-Une Femme {2}\n");
    S("\nOK, et ton nom c'est ");
    getline(&buff, &size, stdin);
    strcpy(datap.player.nom, buff);
    //quet(&datap, buff);
    histoire(datap, buff, size, music);
    return (0);
}