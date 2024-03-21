/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:10:50 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:10:52 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(tack *lista)
{
    if (lista->stack_b[0] == 0)
        return;
    int i = 0;
    while (lista->stack_a[i] != 0)
        i++;
    while (i > 0) {
        lista->stack_a[i] = lista->stack_a[i - 1];
        i--;
    }
    lista->stack_a[0] = lista->stack_b[0];
    i = 0;
    while (lista->stack_b[i] != 0) {
        lista->stack_b[i] = lista->stack_b[i + 1];
        i++;
    }
    write(1, "pa\n", 3);
}
void push_b(tack *lista)
{
    if (lista->stack_a[0] == 0)
        return;
    int i = 0;
    while (lista->stack_b[i] != 0)
        i++;
    while (i > 0)
    {
        lista->stack_b[i] = lista->stack_b[i - 1];
        i--;
    }
    lista->stack_b[0] = lista->stack_a[0];

    i = 0;
    while (lista->stack_a[i] != 0)
    {
        lista->stack_a[i] = lista->stack_a[i + 1];
        i++;
    }
    write(1, "pb\n", 3);
}
