/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:12:57 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:12:59 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(tack *lista)
{
    int temporary;
    int i;

    if (lista->size_a <= 1)
        return;
    temporary = lista->stack_a[0];
    i = 0;
    while (i < lista->size_a - 1)
    {
        lista->stack_a[i] = lista->stack_a[i + 1];
        i++;
    }
    lista->stack_a[lista->size_a - 1] = temporary;
    write(1, "ra\n", 3);
}

void    rotate_b(tack *lista)
{
    int temporary;
    int i;

    if (lista->size_b <= 1)
        return;
    temporary = lista->stack_b[0];
    i = 0;
    while (i < lista->size_b - 1)
    {
        lista->stack_b[i] = lista->stack_b[i + 1];
        i++;
    }
    lista->stack_b[lista->size_b - 1] = temporary;
    write(1, "rb\n", 3);
} 

void    rotate_ab(tack *lista)
{
    rotate_a(lista);
    rotate_b(lista);
    write(1, "rr\n", 3);
} 
