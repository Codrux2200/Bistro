/*
** EPITECH PROJECT, 2020
** infinitadd
** File description:
** infinitadd
*/

#include <stdlib.h>

int my_len(char const *str);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char str);
int my_putstr(char const *str);
char *add(char *dest, char *src);

char *addi(char *st1, char *st2, char *rep)
{
    for (int n = 0, i = (my_len(st1)-1), retenue = 0, result = 0; i >= 0; i--) {
        result = (st1[i] - 48) + (st2[i] - 48) + retenue;
        retenue = 0;
        if (result > 9) {
            retenue = 1;
            if (i == 0) {
                rep[n] = (result % 10) + 48;
                n++;
                rep[n] = (result / 10) + 48;
            } else {
                result = result - 10;
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

char *suppr_menos(char *str)
{
    char *retr = malloc(my_len(str) * sizeof(char *));

    for (int i = 0, r = 0; str[i] != '\0' ; i++ ) {
        if (str[i] != '-') {
            retr[r] = str[i];
            r++;
        }
    }
    return (retr);
}

char *add_menos(char *str)
{
    char *dest = malloc((my_len(str) + 1)  * sizeof(char *));
    dest[0] = '-';
    for (int i = 0; i != my_len(str) ; i++)
        dest[i + 1] = str[i];
    return dest;
}

char *print_str(char *st1, char *st2)
{
    char *rep = malloc((my_len(st1) + 1) * sizeof(char *));

    if ((st1[0] == '-' && st2[0] == '0') || (st1[0] == '-' && st2[0] == '-')
    || (st1[0] == '0' && st2[0] == '-')) {
        return (add_menos(addi(suppr_menos(st1), suppr_menos(st2), rep)));
    } else
        return (addi(suppr_menos(st1), suppr_menos(st2), rep));
}

char *infin_add(char *st1, char *st2)
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
        } else {
            save = malloc(my_len(st2) * sizeof(char *));
            my_strcpy(save, st2);
            st2 = malloc(my_len(st1) * sizeof(char *));
            for (int i = 0; my_len(st1) != my_len(st2) + my_len(save); i++)
                st2[i] = '0';
            add(save, st2);
        }
    }
    return (print_str(st1, st2));
}