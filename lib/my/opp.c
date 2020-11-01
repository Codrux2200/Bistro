/*
** EPITECH PROJECT, 2020
** opp
** File description:
** opp
*/

char *opper(char *str, char *opp)
{
    char classic_opp[7] = "()+-*/%";
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        for (int v = 0; opp[v] != '\0' ; v++) {
            if (opp[v] == str[i]){
                str[i] = classic_opp[v];
            }
        }
    }
    return (str);
}