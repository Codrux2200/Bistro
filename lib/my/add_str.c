/*
** EPITECH PROJECT, 2020
** add_str
** File description:
** add_str
*/

#include <stdlib.h>

char *add_str(char *src)
{
    int n = 0;
    char *cpy = malloc(my_len(src) * sizeof(char *));
    char *par = malloc(my_len(src) * sizeof(char *));

    for (int i = 0, a = 0, count = 0; src[i] != '\0'; i++) {
        if (src[i] == '(' || src[i] == ')' )
            count++;
        else {
            cpy[a] = src[i];
            a++;
        }
    }
    *src = malloc(my_len(cpy) + 2 * sizeof(char *));
    for (int i = 0; cpy[i] != '\0'; i++) {
        src[i] = cpy[i];
        n = i;
    }
    src[n + 1] = 'd';
    src[n + 2] = '\0';
    return (src);
}