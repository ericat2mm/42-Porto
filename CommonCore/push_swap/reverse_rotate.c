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

void reverse_rotate_a(int *stack_a, int size_a)
{
    int temporary;
    int i;

    if (size_a <= 1)
        return;
    temporary = stack_a[size_a - 1];
    i = size_a - 1;
    while (i > 0)
    {
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_a[0] = temporary;
    write(1, "rra\n", 4);
}

void reverse_rotate_b(int *stack_b, int size_b)
{
    int temporary;
    int i;

    if (size_b <= 1)
        return;
    temporary = stack_b[size_b - 1];
    i = size_b - 1;
    while (i > 0)
    {
        stack_b[i] = stack_b[i - 1];
        i--;
    }
    stack_b[0] = temporary;
    write(1, "rrb\n", 4);
}

void    reverse_rotate_ab(int *stack_a, int size_a, int *stack_b, int size_b)
{
    reverse_rotate_a(stack_a, size_a);
    reverse_rotate_b(stack_b, size_b);
    write(1, "rrr\n", 4);
}