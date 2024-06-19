/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:10 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 19:04:40 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void swap(t_stack_node **stack_head)
{
    if (!*stack_head || !(*stack_head)->next)
        return ;
    *stack_head = (*stack_head)->next;
    (*stack_head)->previous->previous = *stack_head;
    (*stack_head)->previous->next = (*stack_head)->next;
    if ((*stack_head)->next)
        (*stack_head)->next->previous = (*stack_head)->previous;
    (*stack_head)->next = (*stack_head)->previous;
    (*stack_head)->previous = NULL;
}
void swap_a(t_stack_node **a, bool print)
{
    swap(a);
    if (!print)
        ft_printf("sa\n");
}
void swap_b(t_stack_node **b, bool print)
{
    swap(b);
    if (!print)
        ft_printf("sb\n");
}
void ss(t_stack_node **a, t_stack_node **b, bool print)
{
    swap(a);
    swap(b);
    if (!print)
        ft_printf("ss\n");
}