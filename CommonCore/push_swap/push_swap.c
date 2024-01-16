/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:09:42 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:10:06 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    initialization_list(t_list **lista, int argc)
{
    *lista = ft_calloc(sizeof(t_list));
    (*lista)->stack_a = ft_calloc(sizeof(int) * (argc - 1)); 
    (*lista)->stack_b = ft_calloc(sizeof(int) * (argc - 1));
    (*lista)->size_a = argc - 1;
    (*lista)->size_b = 0;
    (*lista)->operations = ft_calloc(sizeof(char) * 1000); //1000 e um numero aleatorio que seja grande o suficiente para guardar todas as operacoes
}

int main(int argc, char **argv)
{
    t_list	*lista;

	if (argc == 1)
		return (0);
    check_args(argc, argv);
    check_numbers(argv[1]);
    check_doubles(argc, argv);
    check_limits(argc, argv);
    initialization_list(&lista, argc);
    fill_stack_a(&lista, argc, argv);
    if (check_order(lista) == 1)
    { 
        printf("A lista está ordenada\n");
        print_stack(lista);
        return (0);
    }
    else
        sort_stack(lista);
    printf("lista ordenada:\n");
    print_stack(lista);
    //chamar a funcao que imprime as operacoes feitas
    print_operations(lista);
    return (0);
}
