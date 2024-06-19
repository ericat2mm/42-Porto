/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:57 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 18:01:07 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *tmp;

    if (!*b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    if (*b)
        (*b)->previous = NULL;
    tmp->previous = NULL;
    if (!*a)
    {
        *a = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp->next = *a;
        (*a)->previous = tmp;
        *a = tmp;
    }
}
void	pa(t_stack_node **a, t_stack_node **b, bool print) 
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
    push(b, a);
    if (!print)
        ft_printf("pb\n");
}
