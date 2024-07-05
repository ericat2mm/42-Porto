/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:32:27 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/28 02:44:15 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = *stack;
	if (temp == NULL)
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

bool	sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head->next != NULL)
	{
		if (head->val > head->next->val)
			return (0);
		head = head->next;
	}
	return (1);
}

long	get_bigest(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	temp = *stack;
	max = temp->val;
	while (temp)
	{
		if (temp->val > max)
			max = temp->val;
		temp = temp->next;
	}
	return (max);
}

long	get_lowest(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	temp = *stack;
	min = temp->val;
	while (temp)
	{
		if (temp->val < min)
			min = temp->val;
		temp = temp->next;
	}
	return (min);
}

int	get_position(t_stack **stack, int target)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		if (temp->val == target)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}
