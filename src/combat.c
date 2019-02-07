/*
** EPITECH PROJECT, 2019
** combat.c
** File description:
** 
*/
#include "../include/my.h"

char *spell_menu(char *buff, data_t datap)
{
    size_t size = 100;

    datap.player.spell[0] = NULL;
    S("\nListe de sort :");
    if ((datap.stat.intelligence + datap.weapstat.intelligence) >= 5)
        datap.player.spell[0] = "Heal";
    datap.player.spell[1] = NULL;
    if ((datap.stat.intelligence + datap.weapstat.intelligence) >= 10)
        datap.player.spell[1] = "Boule de feu insignifiante";
    datap.player.spell[2] = NULL;
    if ((datap.stat.intelligence + datap.weapstat.intelligence) >= 15)
        datap.player.spell[1] = "Boule de feu mineure";
    for (int nb = 0; datap.player.spell[nb] != NULL; nb++) {
        sleep(1);
        S("\n-> ");
        S(datap.player.spell[nb]);
        S(" {");
        my_put_nbr(nb + 1);
        S("}");
    }
    S("\n\nje choisis: ");
    getline(&buff, &size, stdin);
    return (buff);
}

void eval_spell(char *buff, data_t *datap)
{
    int save = 0;

    if ((atoi(buff) - 1) == 0) {
        S("\nVous vous soignez de ");
        my_put_nbr(save = random_number((((datap->stat.intelligence + datap->weapstat.intelligence) / 2) - 5), (datap->stat.intelligence + datap->weapstat.intelligence)));
        S(" points de vie, vous avez ");
        datap->player.vie += save;
        if (datap->player.vie > datap->player.vie_max)
            datap->player.vie = datap->player.vie_max;
        my_put_nbr(datap->player.vie);
        S(" points de vie");
    }
    if ((atoi(buff) - 1) == 1) {
        S("\n\nVous vous concentrez et canalisez un boule de feu dans vos main...");
        sleep(2);
        S("\nVotre energie est puissante mais vous ne parvenez pas à la canaliser entièrement");
        sleep(2);
        S("\nVous lancez votre boule de feu sur l'ennemi, il perd ");
        my_put_nbr(save = random_number((datap->stat.intelligence + datap->weapstat.intelligence), (datap->stat.intelligence + datap->weapstat.intelligence) + ((datap->stat.intelligence + datap->weapstat.intelligence) / 2)));
        datap->monster.vie -= save;
        S(" points de vie");
    }
}

int damage(data_t datap)
{
    int save = 0;

    save = ((datap.stat.defense + datap.weapstat.defense) - random_number(datap.monster.damage, datap.monster.damage * 2));
    if (save < 0) {
        datap.player.vie += save;
        my_put_nbr(- (save));
    }
    else
        my_put_nbr(0);
    return (datap.player.vie);
}

void fin_combat(char *buff, data_t datap, sfMusic *music[20])
{
    int save = 0;

    music[3] = sfMusic_createFromFile("lib/song/sounds/mus_act1_spiritworld_passive_lp_110bpm/mus_act1_spiritworld_passive_lp_110bpm");
    S("\n\nBravo !!!\nVous avez battu le Slime, vous gagnez ");
    my_put_nbr((save = random_number(datap.monster.exp_to_give, datap.monster.exp_to_give + datap.player.level)));
    datap.player.expe += save;
    S(" points d'expérience et ");
    my_put_nbr((save = random_number(datap.monster.gold_to_give - 5, datap.monster.gold_to_give + 5)));
    S(" Golds ainsi qu'une Âme");
    datap.player.gold += save;
    datap.player.ame += 1;
    sleep(5);
    system("clear");
    system("amixer set Master 6dB+");
    system("clear");
    sfMusic_destroy(music[2]);
    sfMusic_play(music[3]);
    sfMusic_setLoop(music[3], 1);
    system("clear");
    S("Le calme reviens, les habitants te remercie et reprennent leur occupation respective...");
    sleep(1);
    S("\n\nTu est dans le village, tu est libre, ");
    sleep(1);
    S("tape help pour voir les commande possible");
    sleep(1);
    boucle(buff, datap);
}

void combat_slime(data_t datap, char *buff, sfMusic *music[20])
{
    size_t size = 100;
    int save = 0;
    int i = 0;

    S("\nVous sortez et devant vous se trouve un slime\nVous ne comprenez pas ce qu'un slime fais dans le village\n");
    sleep(1);
    S("\n*Le slime engage le combat*");
    music[1] = sfMusic_createFromFile("lib/song/The Last Encounter Collection/The Last Encounter (90s RPG Version) Full Loop.wav");
    music[2] = sfMusic_createFromFile("lib/song/sounds/mus_act1_spiritworld_intro_110bpm/mus_act1_spiritworld_intro_110bpm");
    sleep(3);
    sfMusic_destroy(music[0]);
    system("clear");
    system("amixer set Master 4dB-");
    system("clear");
    sfMusic_play(music[1]);
    sfMusic_setLoop(music[1], 1);
    system("clear");
    while (datap.monster.vie > 0) {
        sleep(1);
        if (i != 0)
            S("\n\n");
        i++;
        S("Le slime se prépare à attaquer, que fais tu ?");
        buff = choice(4, buff, size, "\n-Attaquer {1} *Force*", "\n-Sort {2} *Intelligence*", "\n-Objet {3}", "\n-Fuir {4}");
        if (atoi(buff) == 1) {
            S("Vous infliger ");
            datap.monster.vie -= (save = random_number((datap.stat.force + datap.weapstat.force) - 2, (datap.stat.force + datap.weapstat.force) + 2));
            my_put_nbr(save);
            S(" dégats au slime");
        }
        if (atoi(buff) == 2 && (datap.stat.intelligence + datap.weapstat.intelligence) >= 5) {
            buff = spell_menu(buff, datap);
            S("\nVous lancer le sort *| ");
            S(datap.player.spell[atoi(buff) - 1]);
            S(" |* !!!");
            eval_spell(buff, &datap);
        }
        else if (atoi(buff) == 2)
            S("\nTu n'as pas assez d'intelligence pour manipuler la magie... Sale mortel.");
        if (atoi(buff) == 3) {
            S("\nTu viens de commencer le jeu, tu crois avoir un truc dans ton inventaire ?");
        }
        if (atoi(buff) == 4) {
            S("\nQuoi ? Fuir ? Au premier combat ?");
            sleep (3);
            S("\nMais tu est quel genre de tapette pour fuir maintenant ?");
            sleep(3);
            S("\nVas y, dit le si tu veux pas jouer hein");
            sleep(3);
            S("\nNan mais c'est bon vas y pars...");
            sleep(3);
            S("\nLe narrateur s'est enfuis, il n'y a personne pour raconter l'histoire, vous tombez dans l'oublie...");
            sleep(1);
            S("  Adieu...\n");
            sleep(2);
            exit(84);
        }
        if (datap.monster.vie <= 0)
            break;
        S("\nLe slime attaque !!");
        sleep(1);
        S("\nIl vous inflige ");
        datap.player.vie = damage(datap);
        S(" dégats !!");
        if (datap.player.vie <= 0) {
            sleep(1);
            S("\n\nDommage, vous etes mort, c'est la vie après tout...");
            exit(0);
        }
        S("\nIl vous reste ");
        my_put_nbr(datap.player.vie);
        S(" points de vie");
    }
    sfMusic_destroy(music[1]);
    sfMusic_play(music[2]);
    sfMusic_setLoop(music[2], 1);
    fin_combat(buff, datap, music);
}