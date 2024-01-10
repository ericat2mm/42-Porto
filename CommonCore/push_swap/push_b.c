/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:11:10 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:11:13 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_b(t_list *lista)
{
    int index;

    index = lista->size_b;
    lista->stack_a = lista->stack_a - 1;
    lista->stack_b = lista->stack_b + 1;
    while (index > 0)
    {
        swap(&lista->stack_b[index], &lista->stack_b[index - 1]);
        index--;
    }
    lista->stack_b[0] = lista->stack_a[0];
    index = 0;
    while (index <= lista->size_a)
    {
        lista->stack_a[index] = lista->stack_a[index + 1];
        index++;
    }
    write(1, "pb\n", 3);
}
