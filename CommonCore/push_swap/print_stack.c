/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:28:21 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/13 11:36:22 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//imprimir a lista da stack a
void print_list_stack_a(int *lista, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ft_putnbr(lista[i]);
        write(1, "\n", 1);
        i++;
    }
}


void ft_putnbr(int n)
{
    char c;

    if (n < 0)
    {
        write(1, "-", 1);
        n = n * -1;
    }
    if (n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
    {
        c = n + '0';
        write(1, &c, 1);
    }
}