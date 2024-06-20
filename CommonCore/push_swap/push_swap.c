/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:02:32 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/20 15:41:21 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);
    if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        initialization_of_stack_a(&a, argv, argc);
    }
    else
        initialization_of_stack_a(&a, argv + 1, argc);
    if(!is_sorted(a))
    {
        if (stack_size(a) == 2)
            swap(&a);
        else if (stack_size(a) == 3)
            sort_three(&a);
        else if (stack_size(a) > 3)
            turkish_algorithm(&a, &b);
    }
    free_stack(a);
    return (0);
}
