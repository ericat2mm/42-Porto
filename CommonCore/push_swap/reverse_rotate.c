/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:41:06 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/28 02:37:58 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack, char leters)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = *stack;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = (*stack);
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
	if (leters == 'a')
		ft_printf("rra\n");
	else if (leters == 'b')
		ft_printf("rrb\n");
	else
		(void)leters;
}

void	reverse_rot_both(t_stack **stack_a, t_stack **stack_b, char l)
{
	if (*stack_a && *stack_b)
	{
		reverse_rotate(stack_a, 'n');
		reverse_rotate(stack_b, 'n');
	}
	else
		return ;
	if (l == 'y')
		ft_printf("rrr\n");
}
