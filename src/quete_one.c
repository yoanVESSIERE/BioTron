/*
** EPITECH PROJECT, 2019
** quete_one.c
** File description:
** 
*/
#include "../include/my.h"

void danger(data_t *data, char *buff)
{
    S("Tu décide de passer par le chemin court, est-ce du courage ? Ou de l'ignorance...");
    sleep(3);
    system("clear");
    S("");
}

int quet(data_t *datap, char *buff)
{
    size_t size = 100;

    sleep(1);
    system("clear");
    S("C'est parti, vous prenez votre courage à deux mains et partez détruire ce dragon !");
    sleep(1);
    S("\nVous prenez le chemin menant aux montagnes où le dragon a été vu");
    sleep(1);
    S("\n\nVous vous retrouvez à une intersection, à droite ce trouve un long chemin contournant la forêt");
    S(" et à gauche un chemin rapide traversant directement la forêt, mais ce chemin vous angoisse...");
    sleep(1);
    S("\nQue faites vous ?");
    buff = choice(3, buff, size, "\n- Chemin long {1}", "\n- Chemin court {2}", "\n- Retour au village {3}");
    if (atoi(buff) == 3) {
        S("\nTu ne te sens pas prêt à affronté le dragon, tu rebrousses chemin...");
        sleep(1);
        S("\nTe revoilà au village !");
        return (0);
    }
    if (atoi(buff) == 1) {
        //safe(datap, buff);
    }
    if (atoi(buff) == 2) {
        danger(datap, buff);
    }
    return (0);
}