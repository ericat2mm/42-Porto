/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:15:00 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/20 15:41:31 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char*    check_syntax_errors(char *argv)
{
    int i;

    i = 0;
    while (argv[i])
    {
        if (!ft_isdigit(argv[i]) && argv[i] != '-' && argv[i] != '+')
            return ("ERROR: INVALID ARGUMENT\n");
        i++;
    }
    return (NULL);
}

char* duplicates(t_stack_node **a, long number)
{
    t_stack_node *temp;

    temp = *a;
    while (temp)
    {
        if (temp->number == number)
            return ("ERROR: DUPLICATE NUMBERS\n");
        temp = temp->next;
    }
    return (NULL);
}

char* free_errors(t_stack_node **a)
{
    free_stack(*a);
    return ("ERROR: SYNTAX ERROR\n");
}

void free_stack(t_stack_node *stack)
{
    t_stack_node *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

void free_argv(char **argv)
{
    int i;

    i = 0;
    while (argv[i])
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}