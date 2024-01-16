/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:09:42 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:10:06 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_two(t_list *lista)
{
    if (lista->stack_a[0] > lista->stack_a[1])
    {
        swap(&lista->stack_a[0], &lista->stack_a[1]);
        ft_strjoin(lista->operations, "sa");
    }
}

static void sort_tree(t_list *lista)
{
    

    while (check_order(lista) == 0)
        sort_tree(lista);
}

static void sort_five(t_list *lista)
{
    //passar os dois primeiros para b
    while (lista->size_a > 3)
        push_b(lista);
    sort_tree(lista->stack_a);
    while (lista->size_b > 0)
        push_a(lista);
    while (check_order(lista) == 0)
        sort_five(lista);
}

void    sort_small_stack(t_list *lista)
{
    if (lista->size_a == 2)
    {
        sort_two(lista);
    }
    else if (lista->size_a == 3)
    {
        sort_tree(lista);
    } 
    else if (lista->size_a == 4)
    {
        sort_four(lista);
    }
    else
        sort_big_stack(lista);
}

void    sort_big_stack(t_list *lista)
{
    
}
