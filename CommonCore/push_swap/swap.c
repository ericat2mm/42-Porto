/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:13:48 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/09 00:59:05 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(int *number1, int *number2)
{
    int temp_var;

    temp_var = *number1;
    *number1 = *number2;
    *number2 = temp_var;
}

void   swap_a(int *sa)
{
    int temp_var;

    temp_var = sa[0];
    sa[0] = sa[1];
    sa[1] = temp_var;
    write(1, "sa\n", 3);
}

void    swap_b(int *sb)
{
    int temp_var;

    temp_var = sb[0];
    sb[0] = sb[1];
    sb[1] = temp_var;
    write(1, "sb\n", 3);
}

void   swap_ab(int *sa, int *sb)
{
    int temp_var_a;
    int temp_var_b;

    temp_var_a = sa[0];
    sa[0] = sa[1];
    sa[1] = temp_var_a;

    temp_var_b = sb[0];
    sb[0] = sb[1];
    sb[1] = temp_var_b;
    write(1, "ss\n", 3);
}