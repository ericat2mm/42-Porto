/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:08:36 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/20 15:46:47 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *initialization_of_stack_a(t_stack_node **a, char **argv, int argc)
{
    int i;
    long number;

    i = 0;
    while (argv[i])
    {
        if (check_syntax_errors(argv[i]))
            free_errors(a);
        number = ft_atol(argv[i]);
        if (number > INT_MAX || number < INT_MIN)
            return ("ERROR: NUMBER OUT OF RANGE\n");
        if(duplicates(a, number))
            return ("ERROR: DUPLICATE NUMBERS\n");
        append_node(a, number);
        i++;
    }
    if (argc == 2)
    {
        while (argv)
            free_argv(argv);
    }
    return (NULL);
}
int	ft_atol(const char *nptr)
{
	char	*str;
    long	result;
    int		sign;
    int		i;

    str = (char *)nptr;
    result = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' 
        || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
        i++;
    if (str[i] == '-')
    {
        sign *= -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - 48;
        i++;
    }
    return (sign * result);
}
void append_node(t_stack_node **stack, int n)
{
    t_stack_node *node;
    t_stack_node *last_node;

    if(!stack)
        return ;
    node = malloc(sizeof(t_stack_node));
    if (!node)
        return ;
    node->next = NULL;
    node->number = n;
    if (!(*stack))
    {
        *stack = node;
        node->previous = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->previous = last_node;
    }
}
void preparation_for_push(t_stack_node **stack, t_stack_node *node, char stack_name)
{
    while ((*stack) != node)
    {
        if (stack_name == 'a')
        {
            if (node->above_median)
                rotate_a(stack, false);
            else
                reverse_rotate_a(stack, false);
        }
        else if (stack_name == 'b')
        {
            if (node->above_median)
                rotate_b(stack, false);
            else
                reverse_rotate_b(stack, false);
        }
    }
}
t_stack_node *set_cheapest(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}