/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:10:29 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/17 18:24:09 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

tack *creation_of_stacks_more_argcs(int argc, char **argv)
{
    tack *lista;
    
    lista = malloc(sizeof(tack));
    lista->size_a = argc - 1;
    ft_printf("asgd");
    lista->size_b = 0;
    lista->stack_a = malloc(sizeof(int) * lista->size_a);
    lista->stack_b = malloc(sizeof(int) * lista->size_b);
    if (lista->stack_a == NULL || lista->stack_b == NULL)
    {
        free(lista->stack_a);
        free(lista->stack_b);
        free(lista);
        return (0);
    }
    while (argc > 1)
    {
        lista->stack_a[argc - 2] = ft_atoi(argv[argc - 1]);
        argc--;
    }
    return (lista);
}

tack *creation_of_stacks_two_argcs(char **temporary)
{
    tack *lista;
    int i;

    
    lista = malloc(sizeof(tack));
    if (lista == NULL)
        return (0); 
    while (temporary[lista->size_a] != NULL)
        lista->size_a++;
    lista->size_b = 0;
    lista->stack_a = malloc(sizeof(int) * lista->size_a);
    lista->stack_b = malloc(sizeof(int) * lista->size_b);
    if (lista->stack_a == NULL || lista->stack_b == NULL)
    {
        free(lista->stack_a);
        free(lista->stack_b);
        free(lista);
        return (0);
    }
    i = 0;
    while (i < lista->size_a)
    {
        lista->stack_a[i] = ft_atoi(temporary[i]);
        i++;
    }
    return (lista);
}

int is_sorted(int size, int *stack)
{
    int i;

    i = 0;
    while (i < size - 1)
    {
        if (stack[i] > stack[i + 1])
            return (1);
        i++;
    }
    return (0);
}

int find_min_index(int *stack_a, int size_a)
{
    int min_index;
    int i;

    min_index = stack_a[0];
    i = 0;
    while (i != size_a)
    {
        if (stack_a[i] < min_index)
            min_index = stack_a[i];
        i++;
    }
    return (min_index);
}