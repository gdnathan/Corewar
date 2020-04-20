/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Two algorithms for integer power calculation
*/

int my_ipow_r(int nb, int p)
{
    if (p > 0)
        return (nb * my_ipow_r(nb, p - 1));
    else if (p < 0)
        return (0);
    else
        return (1);
}

int my_ipow(int nb, int p)
{
    int c = p;
    int result = nb;

    if (c < 0)
        return (0);
    else if (!c)
        return (1);
    while (c > 1) {
        result *= nb;
        c--;
    }
    return (result);
}
