/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:24 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 19:32:51 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_stack_node **stack)
{
    t_stack_node *last_node;

    if (!*stack || !(*stack)->next)
        return ;
    last_node = find_last_node(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    last_node->next->next = NULL;
    last_node->next->previous = last_node;
    last_node->next->next = NULL;
}

void rotate_a(t_stack_node **a, bool print)
{
    rotate(a);
    if (!print)
        ft_printf("ra\n");
}
void    rotate_b(t_stack_node **b, bool print)
{
    rotate(b);
    if (!print)
        ft_printf("rb\n");
}
void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (!print)
        ft_printf("rr\n");
}
