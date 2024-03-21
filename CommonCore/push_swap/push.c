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

void push_a(int *stack_a, int *stack_b)
{
    if (stack_b[0] == 0)
        return;
    int i = 0;
    while (stack_a[i] != 0)
        i++;
    while (i > 0) {
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_a[0] = stack_b[0];
    i = 0;
    while (stack_b[i] != 0) {
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    write(1, "pa\n", 3);
}
void push_b(int *stack_a, int *stack_b)
{
    if (stack_a[0] == 0)
        return;
    int i = 0;
    while (stack_b[i] != 0)
        i++;
    while (i > 0)
    {
        stack_b[i] = stack_b[i - 1];
        i--;
    }
    stack_b[0] = stack_a[0];

    i = 0;
    while (stack_a[i] != 0)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    write(1, "pb\n", 3);
}
