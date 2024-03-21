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

void rotate_a(int *stack_a, int size_a)
{
    int temporary;
    int i;

    if (size_a <= 1)
        return;
    temporary = stack_a[0];
    i = 0;
    while (i < size_a - 1)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    stack_a[size_a - 1] = temporary;
    write(1, "ra\n", 3);
}

void    rotate_b(int *stack_b, int size_b)
{
    int temporary;
    int i;

    if (size_b <= 1)
        return;
    temporary = stack_b[0];
    i = 0;
    while (i < size_b - 1)
    {
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    stack_b[size_b - 1] = temporary;
    write(1, "rb\n", 3);
} 

void    rotate_ab(int *stack_a, int size_a, int *stack_b, int size_b)
{
    rotate_a(stack_a, size_a);
    rotate_b(stack_b, size_b);
    write(1, "rr\n", 3);
} 
