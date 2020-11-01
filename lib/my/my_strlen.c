/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** desc
*/

int my_len(char const *str)
{
    int i = 0;

    while (*str != '\0') {
        str++;
        i++;
    }
    return (i);
}