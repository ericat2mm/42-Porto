/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:12:57 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:12:59 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(t_list *lista)
{
    int index;

    index = 0;
    while (index + 1 < lista->size_a)
    {
        swap(&lista->stack_a[index], &lista->stack_a[index + 1]);
        index++;
    }
    write(1, "ra\n", 3);
} 

void    rotate_b(t_list *lista)
{
    int index;

    index = 0;
    while (index + 1 < lista->size_b)
    {
        swap(&lista->stack_b[index], &lista->stack_b[index + 1]);
        index++;
    }
    write(1, "rb\n", 3);
} 

void    rotate_ab(t_list *lista)
{
    int index;

    index = 0;
    while (index + 1 < lista->size_a)
    {
        swap(&lista->stack_a[index], &lista->stack_a[index + 1]);
        index++;
    }
    index = 0;
    while (index + 1 < lista->size_b)
    {
        swap(&lista->stack_b[index], &lista->stack_b[index + 1]);
        index++;
    }
    write(1, "rr\n", 3);
} 
