/*
** EPITECH PROJECT, 2020
** infin_multip
** File description:
** infin_multip
*/

#include <stdlib.h>

int my_len(char const *str);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char str);
int my_putstr(char const *str);
char *add(char *dest, char *src);
char *infin_add(char *st1, char *st2);
char *transform(int retenue , char *resultf);

char *add_zero(char *resultf , int i)
{
    char *reponse = malloc(my_len(resultf) * sizeof(char *));
    int size = my_len(resultf);
    int taille = 0;
    for (int r = size; r <= (size + i); r++) {
        resultf[r] = '0';
    }
    for (taille = 0; resultf[taille] == '0'; taille++);
    for (int i = taille, v = 0; resultf[i] != '\0' ; i++, v++) {
        reponse[v] = resultf[i];
    }
    return (reponse);
}

char *transfo(char **tab, char *st2, char *st1)
{
    char *fin = malloc((my_len(st1) * my_len(st2)) + sizeof(char *));
    fin = infin_add(tab[0], tab[1]);
    for (int i = 2 ; tab[i] != NULL ; i++) {
        fin = infin_add(fin, tab[i]);
    }
    return (fin);
}

char *transfi(char *resultf, int retenue)
{
    char *retour = malloc((my_len(resultf) + 1) * sizeof(char *));
    int i = 0;
    retour[0] = retenue + 48;
    for (int v = 0, i = 1; v != my_len(resultf) + 1; v++, i++) {
        retour[i] = resultf[v];
    }
    retour[i + 2] = '\0';
    return (my_revstr(retour));
}

char *multi(char *st1, char *st2)
{
    int reponse = 1;
    int retenue = 0;
    char *resultf = malloc((my_len(st1) + 1) * sizeof(char *));
    char **tab = malloc((my_len(st1) * my_len(st2)) * sizeof(char **));
    int n = 0;
    int v = 0;
    int jeux = 0;
    int r = -1;
    for (int i = my_len(st1) - 1; i >= 0 ; i--, jeux++) {
        for (v = my_len(st2) - 1; v >= 0 ; v--) {
            reponse = (st2[v] - 48) * (st1[i] - 48) + retenue;
            retenue = 0;
            if (reponse > 9) {
                retenue = reponse / 10;
                reponse = reponse % 10;
            }
            resultf[n] = (reponse + 48);
            n++;
        }
        if (retenue != 0) {
            if (my_len(st2) == my_len(st1))
                resultf = transfi(my_revstr(resultf), retenue);
            tab[jeux] = add_zero(transform(retenue, my_revstr(resultf)), r);
            retenue = 0;
            n = 0;
        } else {
            tab[jeux] = add_zero(my_revstr(resultf), r);
            n = 0;
        }
        r++;
    }
    if (jeux > 1 && my_len(st1) != 1)
        return (transfo(tab, st2, st1));
    else
        return (my_revstr(resultf));
}

char *infini_multip(char *st1, char *st2)
{
    char *save = "";

    if (my_len(st1) != my_len(st2)) {
        if (my_len(st1) < my_len(st2)) {
            return (multi(st1, st2));
        } else {
            return (multi(st2, st1));
        }
    } else
        return (multi(st2, st1));
}