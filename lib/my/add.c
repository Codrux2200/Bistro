/*
** EPITECH PROJECT, 2020
** add.c
** File description:
** infinitadd
*/

#include <stdlib.h>

char *add(char *dest, char *src)
{
    int p = my_len(src);
    for (int i = 0; p != (my_len(src) + my_len(dest)); p++ , i++)
        src[p] = dest[i];
    free(dest);
    src[p] = '\0';
    return (src);
}