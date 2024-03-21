/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:11:49 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:11:52 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_a(tack *lista)
{
    int temporary;
    int i;

    if (lista->size_a <= 1)
        return;
    temporary = lista->stack_a[lista->size_a - 1];
    i = lista->size_a - 1;
    while (i > 0)
    {
        lista->stack_a[i] = lista->stack_a[i - 1];
        i--;
    }
    lista->stack_a[0] = temporary;
    write(1, "rra\n", 4);
}

void reverse_rotate_b(tack *lista)
{
    int temporary;
    int i;

    if (lista->size_b <= 1)
        return;
    temporary = lista->stack_b[lista->size_b - 1];
    i = lista->size_b - 1;
    while (i > 0)
    {
        lista->stack_b[i] = lista->stack_b[i - 1];
        i--;
    }
    lista->stack_b[0] = temporary;
    write(1, "rrb\n", 4);
}

void    reverse_rotate_ab(tack *lista)
{
    reverse_rotate_a(lista);
    reverse_rotate_b(lista);
    write(1, "rrr\n", 4);
}