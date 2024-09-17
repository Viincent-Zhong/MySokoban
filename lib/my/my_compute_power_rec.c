/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** Write an recursive function that calculate the power of a number.
*/

int my_compute_power_rec(int nb, int p)
{
    int result;
    result = nb;
    if ( p < 0 ){
        return (0);
    }
    if (p == 0 ){
        return (1);
    }
    if ( p >= 2 ){
        result = result * my_compute_power_rec( nb , p - 1 );
        if (result > 2147483647){
            return (0);
        }
    }
}
