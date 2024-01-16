/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:11:30 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:11:33 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stddef.h>
#include <limits.h>

typedef struct  s_list
{
    int stack_a;
    int stack_b;
    int size_a;
    int size_b;
    char *operations;
}t_list;

void    push_a(t_list *lista);
void    push_b(t_list *lista);
void    rotate_a(t_list *lista);
void    rotate_b(t_list *lista);
void    rotate_ab(t_list *lista);
void    reverse_rotate_a(t_list *lista);
void    reverse_rotate_b(t_list *lista);
void    reverse_rotate_ab(t_list *lista);
void    swap_a(t_list *lista);
void    swap_b(t_list *lista);
void    swap_ab(t_list *lista);
void    swap(int *a, int *b);
void    print_stack(t_list *lista);

#endif
