/*
** EPITECH PROJECT, 2020
** test n*2
** File description:
** eval_Expr2
*/

#include <stdlib.h>

void my_put_nbr(int nbr);
int my_getnbr(char *str);
int my_len(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *add_str(char *src);
char *infin_add(char *st1, char *st2);
char *calcul(char **tableauint, char *tableauchar);
char *infini_multip(char *st1, char *st2);
char *infin_soustr(char *st1, char *st2);
char *calcul2(char **tableauint, char *tableauchar, char *result);
char *opper(char *str, char *opp);
char *reglage(int v, char **tableauint1, char *tableauchar1);

int check_repeat(char *base, char *opp)
{
    for (int i = 0; opp[i] != '\0'; i++) {
        for (int v = 0; base[v] != '\0'; v++) {
            if (base[v] == opp[i])
                return (1);
        }
    }
    return (0);
}

char *bases(char *str, char *base, char *opp)
{
    char classic_base[10] = "0123456789";
    char classic_opp[7] = "()+-*/%";
    if (check_repeat(base, opp) == 0) {
        for (int i = 0, count = 0; str[i] != '\0'; i++) {
            for (int v = 0; base[v] != '\0' ; v++) {
                if (base[v] == str[i])
                    str[i] = classic_base[v];
            }
        }
    str = opper(str, opp);
    return (str);
    } else {
        write(2, "ERROR REPETITION CARACTERE IN TWO STRINGS\n", 43);
        return (84);
    }
}

char *eval_expr(char *base, char *opp, char *src)
{
    char *number = malloc((my_len(src) + 20) * sizeof(char *));
    int v = 0;
    char **tableauint1 = malloc(my_len(src) * sizeof(char **));
    char *tableauchar1 =  malloc(my_len(src) * sizeof(char *));
    int compteur = 0;
    int n = 0;

    src = add_str(bases(src, base, opp));
    if (src[0] == '+' || src[0] == '*' || src[0] == '/' || src[0] == '%') {
        write(2, "ERROR SINTAXE\n", 14);
        return (84);
    }
    for (int i = compteur; src[i] != '\0'; i++) {
        if (src[i] >= '0' && src[i] <= '9') {
            number[n] = src[i];
            n++;
        } else {
            n = 0;
            tableauint1[v] = number;
            number = malloc(18 * sizeof(char *));
            tableauchar1[v] = src[i];
            v++;
        }
    }
    tableauchar1[v - 2] = 'd';
    return (reglage(v, tableauint1, tableauchar1));
}

char *calcul(char **tableauint, char *tableauchar)
{
    char *resu = malloc(my_len(tableauint) + my_len(tableauchar) * sizeof(char *));
    if (tableauchar[0] == '+')
        resu = infin_add(tableauint[0], tableauint[1]);
    if (tableauchar[0] == '-')
        resu = infin_soustr(tableauint[0], tableauint[1]);
    if (tableauchar[0] == '*')
        resu = infini_multip(tableauint[0], tableauint[1]);
    return (calcul2(tableauint, tableauchar, resu));
}

char *calcul2(char **tableauint, char *tableauchar, char *result)
{
    for (int i = 1; tableauchar[i] != 'd'; i++) {
            if (tableauchar[i] == '*')
                result = infini_multip(result, tableauint[i + 2]);
            if  (tableauchar[i] == '+')
                result = infin_add(result, tableauint[i + 2]);
            if (tableauchar[i] == '-')
                result = infin_soustr(result, tableauint[i + 2]);
    }
    return (result);
}