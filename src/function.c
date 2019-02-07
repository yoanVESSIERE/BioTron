/*
** EPITECH PROJECT, 2019
** function.c
** File description:
** Biotron
*/
#include "../include/my.h"

int random_number(int min_num, int max_num)
{
    int result = 0;
    int low_num = 0;
    int hi_num = 0;
    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    }
    else {
        low_num = max_num + 1;
        hi_num = min_num;
    }
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return (result);
}

char *choice(int nb, char *buff, size_t size, ...)
{
    va_list list;
    int i = 0;
    int e = 0;
    sfMusic *music = NULL;

    music = sfMusic_createFromFile("lib/song/Bits.wav");
    va_start(list, size);
    sleep(1);
    while (e != nb) {
        S(va_arg(list, char *));
        sleep(1);
        e++;
    }
    va_end(list);
    S("\n\nje choisis: ");
    getline(&buff, &size, stdin);
    sfMusic_play(music);
    while ((i = atoi(buff)) <= 0 || (i = atoi(buff)) > nb) {
        va_start(list, size);
        e = 0;
        S("Mauvais choix\n\n");
        sleep(1);
        while (e != nb) {
            S(va_arg(list, char *));
            sleep(1);
            e++;
        }
        S("\nje choisis: ");
        getline(&buff, &size, stdin);
        sfMusic_play(music);
        va_end(list);
    }
    return (buff);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    if (nb < 0 && (nb * -1) > 9) {
        my_putchar(45);
        nb = nb * -1;
        my_put_nbr(nb / 10);
    }
    else if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    my_putchar(nb % 10 + '0');
    return (0);
}