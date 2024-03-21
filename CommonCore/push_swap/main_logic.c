/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:30:16 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/15 00:05:20 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int two_argcs_logic(char **argv)
{
    char **temporary;
    tack *lista;

    temporary = NULL;
    lista = NULL;
    temporary = ft_split(argv[1], ' ');
    if (two_argcs_verification(temporary) == 1)
        return (0);
    if (doubles_verification(temporary) == 1)
        return (0);
    lista = creation_of_stacks_two_argcs(temporary);
    if (creation_of_stacks_two_argcs(temporary) == 0)
        return (0);
    if (is_sorted(lista->size_a, lista->stack_a) == 1)
        define_sort(lista);
    return (0);
}

int more_argcs_logic(int argc, char **argv)
{
    tack *lista;

    lista = NULL;
    if (more_argcs_verification(argv) == 1)
        return (0);
    if (doubles_verification(argv) == 1)
        return (0);
    lista = creation_of_stacks_more_argcs(argc, argv);
    if (creation_of_stacks_more_argcs(argc, argv) == 0)
        return (0);
    if (is_sorted(lista->size_a, lista->stack_a) == 1)
        define_sort(lista);
    return (0);
}
