/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:24:07 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 18:56:30 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *find_last_node(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

bool is_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->number > stack->next->number)
            return (false);
        stack = stack->next;
    }
    return (true);
}
void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node;

    cheapest_node = set_cheapest(*a);
    if (cheapest_node->above_median && 
        cheapest_node->target_node->above_median)
        rr(a, b, cheapest_node);
    else if (!cheapest_node->above_median && 
        !cheapest_node->target_node->above_median)
        rrr(a, b, cheapest_node);
    preparation_for_push(a, cheapest_node, 'a');
    preparation_for_push(b, cheapest_node->target_node, 'b');
    pb(b, a, false);
}
void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    preparation_for_push(a, (*b)->target_node, 'a');
    pa(a, b, false);
}

int stack_size(t_stack_node *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        stack = stack->next;
        ++i;
    }
    return (i);
}