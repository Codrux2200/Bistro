/*
** EPITECH PROJECT, 2020
** transform
** File description:
** transform
*/
int my_len(char const *str);

char *transform(int retenue , char *resultf)
{
    char *retour = malloc((my_len(resultf) + 1) * sizeof(char *));
    int i = 0;
    retour[0] = retenue + 48;
    for (int v = 0, i = 1; v != my_len(resultf); v++, i++) {
        retour[i] = resultf[v];
    }
    retour[i + 1] = '\0';
    return (retour);
}