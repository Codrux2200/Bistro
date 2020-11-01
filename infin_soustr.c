/*
** EPITECH PROJECT, 2020
** infin_soustr
** File description:
** infin_soustr
*/

#include <stdlib.h>

char *add_menos(char *str);
int my_len(char const *str);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char *str);
int my_putstr(char const *str);
char *add(char *dest, char *src);

char *soustr(char *st1, char *st2)
{
    char *rep = malloc((my_len(st1) + 1) * sizeof(char *));
    int i = (my_len(st1)-1);

    for (int n = 0, retenue = 0, retenue2 = 0, result = 0; i >= 0; i--) {
        if (st1[i] < st2[i])
            retenue2 = 10;
        result = ((st1[i] - 48) + retenue2) - ((st2[i] - 48) + retenue);
        retenue = 0;
        if (st1[i] < st2[i])
            retenue = 1;
        retenue2 = 0;
        if (i == 0) {
            if (result != 0) {
                rep[n] = result + 48;
                n++;
            }
        } else {
            rep[n] = result + 48;
            n++;
        }
    }
    return (my_revstr(rep));
}

char *test(char *st1,  char *st2)
{
    if (my_getnbr(st1) < my_getnbr(st2))
        return (add_menos(soustr(st2, st1)));
    else
        return (soustr(st1, st2));
}

char *infin_soustr(char *st1, char *st2)
{
    char *save = "";

    if (my_len(st1) != my_len(st2)) {
        if (my_len(st1) < my_len(st2)) {
            save = malloc(my_len(st1) * sizeof(char *));
            my_strcpy(save, st1);
            st1 = malloc(my_len(st2) * sizeof(char *));
            for (int i = 0; my_len(st2) != my_len(st1) + my_len(save); i++)
                st1[i] = '0';
            add(save, st1);
            return (add_menos(soustr(st2, st1)));
        } else {
            save = malloc(my_len(st2) * sizeof(char *));
            my_strcpy(save, st2);
            st2 = malloc(my_len(st1) * sizeof(char *));
            for (int i = 0; my_len(st1) != my_len(st2) + my_len(save); i++)
                st2[i] = '0';
            add(save, st2);
            return (soustr(st1, st2));
        }
    }
    test(st1, st2);
}