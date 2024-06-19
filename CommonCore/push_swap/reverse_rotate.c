/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:38 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 18:41:42 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack_node **stack)
{
    t_stack_node *last_node;

    if (!*stack || !(*stack)->next)
        return ;
    last_node = find_last_node(*stack);
    last_node->previous->next = NULL;
    last_node->next = *stack;
    last_node->previous = NULL;
    last_node->next = *stack;
    *stack = last_node;
    last_node->next->previous = last_node;
}
void reverse_rotate_a(t_stack_node **a, bool print)
{
    reverse_rotate(a);
    if (!print)
        ft_printf("rra\n");
}
void reverse_rotate_b(t_stack_node **b, bool print)
{
    reverse_rotate(b);
    if (!print)
        ft_printf("rrb\n");
}
void rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (!print)
        ft_printf("rrr\n");
}