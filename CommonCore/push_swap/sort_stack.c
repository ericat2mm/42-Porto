/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:05 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/17 18:37:19 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void define_sort(int *stack_a, int size_a, int *stack_b, int size_b)
{
    if (size_a == 2)
    {
        swap(&stack_a[0], &stack_a[1]);
        write(1, "sa\n", 3);
    }
    else if (size_a == 3)
        sort_three(stack_a);
    else if (size_a == 4)
        sort_four(stack_a, stack_b, size_a);
    else if (size_a == 5)
        sort_five(stack_a, stack_b, size_a);
    else
        sort_big(stack_a, stack_b, size_a, size_b);
}

void sort_three(int *stack_a)
{
    if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
        && stack_a[0] < stack_a[2])
        swap_a(stack_a);
    else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2]
        && stack_a[0] > stack_a[2])
    {
        swap_a(stack_a);
        reverse_rotate_a(stack_a, 3);
    }
    else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
        && stack_a[0] > stack_a[2])
        rotate_a(stack_a, 3);
    else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
        && stack_a[0] < stack_a[2])
    {
        swap_a(stack_a);
        rotate_a(stack_a, 3);
    }
    else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
        && stack_a[0] > stack_a[2])
        reverse_rotate_a(stack_a, 3);
}

void sort_four(int *stack_a, int *stack_b, int size_a) 
{
    int min_index;
    
    min_index = find_min_index(stack_a, size_a);
    if (min_index == stack_a[1])
        swap_a(stack_a);
    else if (min_index == stack_a[2])
    {
        rotate_a(stack_a, size_a);
        swap_a(stack_a);
    }
    else if (min_index == stack_a[3])
        reverse_rotate_a(stack_a, size_a);
    push_b(stack_a, stack_b);
    size_a--;
    sort_three(stack_a);
    push_a(stack_a, stack_b);
}

void sort_five(int *stack_a, int *stack_b, int size_a)
{
    int min_index;
    
    min_index = find_min_index(stack_a, size_a);
    while(min_index != stack_a[0])
        rotate_a(stack_a, size_a);
    push_b(stack_a, stack_b);
    size_a--;
    sort_four(stack_a, stack_b, size_a);
    push_a(stack_a, stack_b);

}

void sort_big(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int i;
    
    i = -1;
    while(++i != 2)
    {
        push_b(stack_a, stack_b);
        size_a--;
    }
    while (size_a != 3)
    {
        while(stack_b[i])
        {
            lowest = get_lowest(stack_b, size_b);
            highest = get_highest(stack_b, size_b);
            if ((stack_a[0] - lowest) < (stack_a[0] - highest))
                get_count()
        }
    }

}