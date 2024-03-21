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
    write(1, "asd", 3);
    if (two_argcs_verification(temporary) == 1)
        return (0);
    write(1, "OK", 2);
    if (doubles_verification(temporary) == 1)
        return (0);
    write(1, "OK2", 3);
    lista = creation_of_stacks_two_argcs(temporary);
    if (creation_of_stacks_two_argcs(temporary) == 0)
        return (0);
    write(1, "OK3\n", 4);
    if (is_sorted(lista->size_a, lista->stack_a) == 1)
        define_sort(lista->stack_a, lista->size_a, lista->stack_b, lista->size_b);
    write(1, "ok4\n", 4);
    if (is_sorted(lista->size_a, lista->stack_a) == 0)
        write(1, "----lista ordenada----\n", 23);
    return (0);
}

int more_argcs_logic(int argc, char **argv)
{
    tack *lista;

    lista = NULL;
    if (more_argcs_verification(argv) == 1)
        return (0);
    write(1, "ok", 2);
    if (doubles_verification(argv) == 1)
        return (0);
    write(1, "ok2", 3);
    lista = creation_of_stacks_more_argcs(argc, argv);
    if (creation_of_stacks_more_argcs(argc, argv) == 0)
        return (0);
    write(1, "ok3\n", 4);
    //vamos verificar se a lista da stack a esta ordenada
    if (is_sorted(lista->size_a, lista->stack_a) == 1)
        define_sort(lista->stack_a, lista->size_a, lista->stack_b, lista->size_b);
            print_list_stack_a(lista->stack_a, lista->size_a);

    write(1, "ok4\n", 4);
    return (0);
}
