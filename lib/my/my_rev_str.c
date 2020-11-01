/*
** EPITECH PROJECT, 2020
** my_rev_str.c
** File description:
** my_rev_str
*/

#include <stdlib.h>

int my_len(char const *str);

char *my_revstr(char *str)
{
    char *cpy = malloc(my_len(str) * sizeof(char *));
    int taille = my_len(str);
    int i = my_len(str)-1;

    for (int s = 0; s != (taille); s++ , i--)
        cpy[s] = str[i];

    return (cpy);
}