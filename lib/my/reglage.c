/*
** EPITECH PROJECT, 2020
** reg
** File description:
** reglage
*/

#include <stdlib.h>

char *calcul(char **tableauint , char *tableauchar);

char *reglage(int v, char **tableauint1, char *tableauchar1)
{
    char **tableauint = malloc((v) * sizeof(char **));
    char *tableauchar = malloc((v * 2) * sizeof(char *));
    int s = 0;
    int z = 0;
    for (int i = 0; tableauchar1[i] != 'd'; i++) {
        if (tableauchar1[i] == '/' || tableauchar1[i] == '%'
        || tableauchar1[i] == '*'){
            tableauchar[z] = tableauchar1[i];
            tableauint[s] = tableauint1[i];
            s++;
            tableauint[s] = tableauint1[i + 1];
            s++;
            z++;
        }
    }
    for (int i = 0; tableauchar1[i] != 'd' ; i++) {
        if (tableauchar1[i] == '+' || tableauchar1[i] == '-') {
            tableauchar[z] = tableauchar1[i];
            tableauint[s] = tableauint1[i];
            s++;
            tableauint[s] = tableauint1[i + 1];
            s++;
            z++;
        }
    }
    tableauchar[z + 1] = 'd';
    return (calcul(tableauint, tableauchar));
}