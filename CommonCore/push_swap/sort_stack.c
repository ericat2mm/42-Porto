/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:05 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/17 18:37:19 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void define_sort(tack *lista)
{
    if (lista->size_a == 2)
    {
        swap(&lista->stack_a[0], &lista->stack_a[1]);
        write(1, "sa\n", 3);
    }
    else if (lista->size_a == 3)
        sort_three(lista);
    else if (lista->size_a == 4)
        sort_four(lista);
    else if (lista->size_a == 5)
        sort_five(lista);
    else
        sort_big(lista);
}

void sort_three(tack *lista)
{
    int *stack_a;

    stack_a = lista->stack_a;
    if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
        && stack_a[0] < stack_a[2])
        swap_a(stack_a);
    else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2]
        && stack_a[0] > stack_a[2])
    {
        swap_a(stack_a);
        reverse_rotate_a(lista);
    }
    else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
        && stack_a[0] > stack_a[2])
        rotate_a(lista);
    else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
        && stack_a[0] < stack_a[2])
    {
        swap_a(stack_a);
        rotate_a(lista);
    }
    else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
        && stack_a[0] > stack_a[2])
        reverse_rotate_a(lista);
}

void sort_four(tack *lista) 
{
    int min_index;
    
    min_index = find_min_index(lista);
    if (min_index == lista->stack_a[1])
        swap_a(lista->stack_a);
    else if (min_index == lista->stack_a[2])
    {
        rotate_a(lista);
        swap_a(lista->stack_a);
    }
    else if (min_index == lista->stack_a[3])
        reverse_rotate_a(lista);
    push_b(lista);
    
    lista->size_a--;
    print_list_stack_a(lista);
    write(1, "\n", 1);
    lista->size_b++;
    print_list_stack_b(lista);
    sort_three(lista);
    push_a(lista);
}

void sort_five(tack *lista)
{
    int min_index;
    
    min_index = find_min_index(lista);
    while(min_index != lista->stack_a[0])
        rotate_a(lista);
    push_b(lista);
    lista->size_a--;
    sort_four(lista);
    push_a(lista);

}

void sort_big(tack *lista)
{
    int i;
    
    i = 0;
    while(++i <= 2)
    {
        push_b(lista);
        lista->size_a--;
        lista->size_b++;
    }
    while (lista->size_a != 3)
    {
        turkish_algorithm_to_b(lista);
        lista->size_a--;
    }
    
}
