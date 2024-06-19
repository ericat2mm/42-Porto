/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:49:54 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 18:14:55 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initialization_node_a(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_node_a(a, b);
    set_cost(a, b);
    set_cheapest(a);
}
void current_index(t_stack_node *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = stack_size(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i++ <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        ++i;
    }
}
void set_target_node_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current_b;
    t_stack_node *target_node;
    long    best_match_index;

    while (a)
    {
        current_b = b;
        best_match_index = LONG_MIN;
        while (current_b)
        {
            if (current_b->number < a->number &&
                current_b->number > best_match_index)
            {
                best_match_index = current_b->number;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_index == LONG_MIN)
            a->target_node = find_max(b);
        else
            a->target_node = target_node;
        a = a->next;
    }
}
t_stack_node *find_max(t_stack_node *b)
{
    t_stack_node *max_node;
    long current;

    if (!b)
        return(NULL);
    current = LONG_MIN;
    while (b)
    {
        if (b->number > current)
        {
            current = b->number;
            max_node = b;
        }
        b = b->next;
    }
    return (max_node);
}
void set_cost(t_stack_node *a, t_stack_node *b)
{
    int len_a;
    int len_b;

    len_a = stack_size(a);
    len_b = stack_size(b);
    while (a)
    {
        a->cost = a->index;
        if (!(a->above_median))
            a->cost = len_a - (a->index);
        if (a->target_node->above_median)
            a->cost += a->target_node->index;
        else
            a->cost += len_b - (a->target_node->index);
        a = a->next;
    }
}


