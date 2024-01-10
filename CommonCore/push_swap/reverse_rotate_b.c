/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:12:30 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:12:35 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
