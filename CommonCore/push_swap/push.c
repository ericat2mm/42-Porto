/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:42:24 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/28 02:43:02 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_sender, t_stack **stack_receiver, char c)
{
	t_stack	*temp;

	if (!*stack_sender)
		return ;
	temp = *stack_sender;
	*stack_sender = (*stack_sender)->next;
	if (*stack_sender)
		(*stack_sender)->prev = NULL;
	temp->next = *stack_receiver;
	if (*stack_receiver)
		(*stack_receiver)->prev = temp;
	*stack_receiver = temp;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
	else
		(void)c;
}
