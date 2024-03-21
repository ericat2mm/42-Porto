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

int two_argcs_verification(char **temporary)
{
    //verificar se os argumentos sao numeros
    //caso seja so um argumento, como ja fizemos o split, vamos verificar se sao todos numeros
    int i;
    int j;

    i = 0;
    j = 0;
    while (temporary[i] != NULL)
    {
        j = 0;
        while (temporary[i][j] != '\0')
        {
            if (ft_isdigit(temporary[i][j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int more_argcs_verification(char **argv)
{
    //verificar se os argumentos sao numeros
    //caso seja mais de um argumento, vamos verificar se sao todos numeros
    int i;
    int j;
    
    i = 1;
    j = 0;
    while (argv[i] != NULL)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (ft_isdigit(argv[i][j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


int doubles_verification(char **argv)
{
    int i;
    int j;
    char **numbers;

    i = 0;
    j = 0;
    numbers = argv;
    while (numbers[i] != NULL)
    {
        while (numbers[j] != NULL)
        {
            if (ft_strcmp(numbers[i], numbers[j]) == 0 && i != j)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0); //sao iguais
    return (1); //nao sao iguais
}