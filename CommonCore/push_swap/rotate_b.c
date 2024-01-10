/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:13:34 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:13:36 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
