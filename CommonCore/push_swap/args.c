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
    int i;
    int j;

    i = 0;
    while (temporary[i] != NULL)
    {
        j = 0;
        if (temporary[i][j] == '-' || temporary[i][j] == '=')
            j++;
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
    int i;
    int j;
    
    i = 1;
    while (argv[i] != NULL)
    {
        j = 0;
        if (argv[i][j] == '-' || argv[i][j] == '=')
            j++;
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
    while(numbers[i])
    {
        j = i + 1;
        while(numbers[j])
        {
            if (ft_atol(numbers[i]) == ft_atol(numbers[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
