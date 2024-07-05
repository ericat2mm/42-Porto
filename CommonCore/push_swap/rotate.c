/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:40:28 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/28 02:37:46 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char leters)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	*stack = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
	if (leters == 'a')
		ft_printf("ra\n");
	else if (leters == 'b')
		ft_printf("rb\n");
	else
		(void)leters;
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, char l)
{
	if (*stack_a && *stack_b)
	{
		rotate(stack_a, 'n');
		rotate(stack_b, 'n');
	}
	else
		return ;
	if (l == 'y')
		ft_printf("rr\n");
}
