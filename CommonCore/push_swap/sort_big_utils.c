/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:22:32 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/17 18:38:16 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void turkish_algorithm_to_b(tack *lista)
{
    int i;
    int lowest;
    int highest;
    i = 0;
    if(lista->stack_a[i] != '\0')
    {
        lowest = get_lowest(lista);
        highest = get_highest(lista);
        if (distance(highest, lista->stack_a[0]) 
            < distance(lowest, lista->stack_a[0]))
        {
            while(lista->stack_b[0] != highest)
                sort_list(lista, highest);
            push_b(lista);
        }
        else
        {
            while(lista->stack_b[0] != lowest)
                sort_list(lista, lowest);
            push_b(lista);
        }
    }
}
int get_lowest(tack *lista)
{
    int i;
    int lowest;

    i = 1;
    lowest = lista->stack_b[0];
    while(lista->stack_b[i] != '\0')
    {
        if (lista->stack_b[i] < lowest)
            lowest = lista->stack_b[i];
        i++;
    }
    return(lowest);
}
int get_highest(tack *lista)
{
    int i;
    int highest;

    i = 1;
    highest = lista->stack_b[0];
    while(lista->stack_b[i] != '\0')
    {
        if (lista->stack_b[i] > highest)
            highest = lista->stack_b[i];
        i++;
    }
    return(highest);
}
int distance(int end, int start)
{
    int distance;

    distance = end - start;
    return(distance);
}
void sort_list(tack *lista, int target)
{
    int i;

    i = 0;
    if (lista->stack_b[0] == target)
        return ;
    if (i <= (lista->size_b/2))
    {
        while(lista->stack_b[0] != target)
            rotate_b(lista);
    }
    else
        while(lista->stack_b[0] != target)
            reverse_rotate_b(lista);
}