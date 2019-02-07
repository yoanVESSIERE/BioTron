/*
** EPITECH PROJECT, 2019
** quete_one.c
** File description:
** 
*/
#include "../include/my.h"

int quet(data_t *datap, char *buff)
{
    size_t size = 100;

    sleep(1);
    system("clear");
    S("C'est parti, vous prenez votre courage à deux mains et partez détruire ce dragon !");
    sleep(1);
    S("\nVous prenez le chemin menant aux montagnes où le dragon a été vu");
    sleep(1);
    S("\n\nVous vous retrouvez à une intersection, a droite ce trouve un chemin long contournant la forêt");
    S(" et a gauche un chemin rapide traversant directement la forêt, mais ce chemin vous angoisse...");
    sleep(1);
    S("\nQue faites vous ?");
    buff = choice(3, buff, size, "\n- Long chemin {1}", "\n- Court chemin {2}", "\n- Retour au village {3}");
    if (atoi(buff) == 3) {
        S("\nTu ne te sens pas prêt à affronté le dragon, tu rebrousse chemin...");
        sleep(1);
        S("\nTe revoila au village !");
        return (0);
    }
    /*if (atoi(buff) == 1) {

    }
    if (atoi(buff) == 2) {

    }*/
    return (0);
}