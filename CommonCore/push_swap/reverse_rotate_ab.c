/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:12:11 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:12:13 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
