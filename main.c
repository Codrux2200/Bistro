/*
** EPITECH PROJECT, 2020
** bistro
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6
#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84
#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

int my_putstr(char const *str);
int my_len(char const *str);
int my_getnbr(char const *str);
char *eval_expr(char *base, char *opp, char *src);

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_len(ops) < 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_len(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

void message(void)
{
    my_putstr("USAGE : \n");
    my_putstr("./calc base operators size_read\n");
    my_putstr("\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols");
    my_putstr("for the parentheses and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            message();
        else {
            my_putstr("Usage: ");
            my_putstr(av[0]);
            my_putstr(" base ops\"()+_*/%\" exp_my_len\n");
        }
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size + 1);
    my_putstr(eval_expr(av[1], av[2], expr));
    my_putstr("\n");
    return (EXIT_SUCCESS);
}