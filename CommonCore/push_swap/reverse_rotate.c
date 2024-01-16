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

void    reverse_rotate_a(t_list *lista)
{
    int index;

    index = lista->size_a - 1;
    while (i > 0)
    {
        swap(&lista->stack_a[i], &lista->stack_a[i - 1]);
        i--;
    }
    write(1, "rra\n", 4);
}

void    reverse_rotate_a(t_list *lista)
{
    int index;

    index = lista->size_b - 1;
    while (i > 0)
    {
        swap(&lista->stack_b[i], &lista->stack_b[i - 1]);
        i--;
    }
    write(1, "rrb\n", 4);
}

void    reverse_rotate_ab(t_list *lista)
{
    int index;

    index = lista->size_a - 1;
    while (i > 0)
    {
        swap(&lista->stack_a[i], &lista->stack_a[i - 1]);
        i--;
    }
    index = lista->size_b - 1;
    while (i > 0)
    {
        swap(&lista->stack_b[i], &lista->stack_b[i - 1]);
        i--;
    }
    write(1, "rrr\n", 4);
}