/*
** EPITECH PROJECT, 2019
** loop.c
** File description:
** 
*/
#include "my.h"

int mag_mag(data_t *datap, char *buff)
{
    //int i = 0;
    size_t size = 100;
    static int nb_ame = 5;

    S("\nJe vois que tu aimerais en savoir plus sur la magie... Suis moi dans l'arrière boutique");
    sleep(1);
    S("\nEn échange d'Âme de monstre je peux t'apprendre des sorts !");
    sleep(1);
    S("\nAvec minimum ");
    my_put_nbr(nb_ame);
    S(" Âme, je peux t'échanger un sort");
    if (datap->player.ame < nb_ame) {
        sleep(1);
        S("\nJe vois que tu n'as pas assez d'Âme, reviens me voir plus tard.\n\nVous sortez de la boutique");
        return (0);
    }
    S("\nQue veux tu ?");
    buff = choice(1, buff, size, "\n- Retour {1}");
    if (atoi(buff) == 1)
        return (0);
    return (0);
}

int buyer(data_t *datap, char *buff)
{
    size_t size = 100;
    int i = 0;
    int nb = 1;

    S("\nQue fais tu ?");
    buff = choice(3, buff, size, "\n- Acheter {1}", "\n- Magie {2}","\n- Retour {3}");
    if (atoi(buff) == 3)
        return (0);
    if (atoi(buff) == 2) {
        mag_mag(datap, buff);
        return (0);
    }
    sleep(1);
    S("\n\nJ'ai de nombreux articles !!");
    sleep(1);
    S("\nQue veux tu ?");
    buff = choice(2, buff, size, "\n- Potion de soin |5 Golds| {1}", "\n- Retour {2}");
    if (atoi(buff) == 2) {
        S("\nAurevoir le jeune !");
        return (0);
    }
    if (atoi(buff) == 1) {
        S("\nCombien en prend tu ?\n-> ");
        getline(&buff, &size, stdin);
        nb = atoi(buff);
        if (datap->player.gold < 5 * nb)
            S("\nNe m'arnaquer pas ! Vous n'avez pas assez d'argent !");
        else {
            datap->player.gold -= (5 * nb);
            for (i = 0; datap->player.inv[i] != NULL; i++);
            datap->player.inv[i] = "Potion de soin";
            datap->player.tab_inv[i] += nb;
            S("\nCe sont les meilleurs du village !\nA bientôt !\nVous sortez du magasins");
        }
    }
    return (0);
}

void comp_part_one(char *buff, data_t *datap)
{
    static int i = 0;

    if (strncmp("help", buff, 4) == 0) {
        S("\n-> Tapez inv pour voir votre inventaire");
        S("\n-> Tapez stat pour voir vos statistique");
        S("\n-> Tapez statw pour voir les statistiques de votre arme");
        S("\n-> Tapez quest pour voir continuer votre quête");
        S("\n-> Tapez pnj pour voir parler aux personnes aux alentours");
        S("\n-> Tapez market pour accéder au marché du village\n");
    }
    if (strncmp("inv", buff, 3) == 0) {
        S("\n\nVous disposez de ");
        my_put_nbr(datap->player.gold);
        S(" Golds et de ");
        my_put_nbr(datap->player.ame);
        S(" Âme");
        S("\nVous êtes équipé de : ");
        S(datap->player.weapon);
        S("\n");
        for (int e = 0; datap->player.inv[e] != NULL; e++) {
            S("Inventaire :\n--->");
            my_put_nbr(datap->player.tab_inv[e]);
            S(" ");
            S(datap->player.inv[e]);
        }
    }
    if (strncmp("stat", buff, 4) == 0 && buff[4] != 'w') {
        S("\n\nForce de votre personnage: ");
        my_put_nbr(datap->stat.force);
        S("\nIntelligence de votre personnage: ");
        my_put_nbr(datap->stat.intelligence);
        S("\nDéfense de votre personnage: ");
        my_put_nbr(datap->stat.defense);
    }
    if (strncmp("statw", buff, 5) == 0) {
        S("\n\nForce de votre arme: ");
        my_put_nbr(datap->weapstat.force);
        S("\nIntelligence de votre arme: ");
        my_put_nbr(datap->weapstat.intelligence);
        S("\nDéfense de votre arme: ");
        my_put_nbr(datap->weapstat.defense);
    }
    if (strncmp("pnj", buff, 3) == 0 && i == 0) {
        S("\n\nVous vous approchez des villageois,");
        sleep(1);
        S("\nBonjour ");
        S(datap->player.nom);
        S("Je suis Meunier, le meunier du village, et j'ai entendu une rumeur comme quoi un dragon était dans les parages !!");
        S("\nOccupez vous de lui et je vous offrirais une récompense !");
        i = 1;
    }
    if (strncmp("quest", buff, 5) == 0 && i == 0) {
        S("\n\nVous n'avez aucune quêtes, parlez au villageois !");
    }
    if (strncmp("quest", buff, 5) == 0 && i == 1) {
        quet(datap, buff);
    }
    if (strncmp("market", buff, 6) == 0) {
        S("\n\nVous allez au magasins");
        buyer(datap, buff);
    }
}

void comp(char *buff, data_t *datap)
{
    comp_part_one(buff, datap);
}

void boucle(char *buff, data_t datap)
{
    size_t size;

    while (1) {
        S("\n->");
        getline(&buff, &size, stdin);
        comp(buff, &datap);
    }
}