/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:43:36 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/28 03:33:51 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	if (argc == 1)
		return (1);
	else if (!process_args(argc, argv, &stack_a) || argv[1] == NULL)
	{
		return (write(2, "Error\n", 7), EXIT_SUCCESS);
	}
	if (sorted(&stack_a))
	{
		return (free_stack(stack_a), EXIT_SUCCESS);
	}
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	while (sorted(&stack_a) != true)
	{
		if (stacksize(&stack_a) / 2
			>= get_position(&stack_a, get_cheapest_to_final(&stack_a)))
			rotate(&stack_a, 'a');
		else
			reverse_rotate(&stack_a, 'a');
	}
	free_stack(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(stack_a) == 2)
		swap_a(stack_a);
	else if (stacksize(stack_a) == 3)
		sort_three(stack_a);
	else if (stacksize(stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	get_cheapest_to_final(t_stack **stack_a)
{
	int		cheapest;
	int		moves;
	int		cost;
	t_stack	*temp;

	temp = *stack_a;
	cheapest = temp->val;
	cost = INT_MAX;
	while (temp)
	{
		moves = targetdist(stack_a, temp->val);
		if (cost > moves)
		{
			cheapest = temp->val;
			cost = moves;
		}
		if (moves <= 1)
			return (cheapest);
		temp = temp->next;
	}
	return (cheapest);
}
