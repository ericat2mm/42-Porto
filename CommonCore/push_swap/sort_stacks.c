/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:01 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 18:53:56 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack_node **a)
{
    t_stack_node    *biggest_node;

    biggest_node = find_max(*a);
    if (biggest_node == *a)
        rotate_a(a, false);
    else if ((*a)->next == biggest_node)
        reverse_rotate_a(a, false);
    if ((*a)->number > (*a)->next->number)
        swap_a(a, false);
}

void turkish_algorithm (t_stack_node **a, t_stack_node **b)
{
    int len_a;

    len_a = stack_size(*a);
    if (len_a-- > 3 && !is_sorted(*a))
        pb(b, a, false);
    if (len_a-- > 3 && !is_sorted(*a))
        pb(b, a, false);
    while (len_a-- > 3 && !is_sorted(*a))
    {
        initialization_node_a(*a, *b);
        move_a_to_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        initialization_node_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}

void min_on_top (t_stack_node **a)
{
    while ((*a)->number != find_min(*a)->number)
    {
        if ((*a)->next->number == find_min(*a)->number)
            rotate_a(a, false);
        else
            reverse_rotate_a(a, false);
    }
}

t_stack_node *find_min(t_stack_node *stack)
{
   long min;
    t_stack_node *temp;

    if(!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->number < min)
        {
            min = stack->number;
            temp = stack;
        }
        stack = stack->next;
    }
    return (temp);
}