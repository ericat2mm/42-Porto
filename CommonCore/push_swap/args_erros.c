/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_erros.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:09:42 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:10:06 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(int argc, char **argv)
{
    int index;

    index = 0;
    while (index < argc)
    {
        check_numbers(argv[index]); 
        if (check_numbers(argv[index]) == -1)
            return("Existem argumentos que nao sao numeros\n");
        index++;
    }
}

int check_numbers(char *str) //verifica se os argumentos sao numeros
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (str[j] == '-' && str[j + 1] >= '0' && str[j + 1] <= '9')
    {
        i++;
        j++;
        while (str[j])
        {
            if (str[j] < '0' || str[j] > '9')
                return(-1);
            j++;
        }
    }
    if (i == ft_strlen(str)) 
        return(0);
}

void    check_doubles(int argc, char **argv)
{
    int index;

    index = 1;
    while (index < argc)
    {
        if (ft_atoi(argv[index]) == ft_atoi(argv[index + 1]))
            return("Existem numeros repetidos\n");
        index++;
    }
}

void    check_limits(int argc, char **argv)
{
    int index;

    index = 1;
    while (index < argc)
    {
        if (ft_atoi(argv[index]) > INT_MAX || ft_atoi(argv[index]) < INT_MIN)
            return("Existem numeros que nao pertencem ao intervalo dos inteiros\n");
        index++;
    }
}