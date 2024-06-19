/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:16:04 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 19:48:52 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    initialization_node_b(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_node_b(a, b);
}

void set_target_node_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current_a;
    t_stack_node *target_node;
    long    best_match_index;

    while (b)
    {
        current_a = a;
        best_match_index = LONG_MAX;
        while (current_a)
        {
            if (current_a->number > b->number &&
                current_a->index < best_match_index)
            {
                best_match_index = current_a->index;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        b->target_node = target_node;
        b = b->next;
    }
}
