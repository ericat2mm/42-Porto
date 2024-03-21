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

void quick_sort(int *stack, int size)
{
    quick_sort_recursive(stack, 0, size - 1);
}

void quick_sort_recursive(int *stack, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(stack, low, high);
        quick_sort_recursive(stack, low, pivot - 1);
        quick_sort_recursive(stack, pivot + 1, high);
    }
}

int partition(int *stack, int low, int high)
{
    int pivot;
    int i;
    int j;

    pivot = stack[high];
    i = low - 1;
    j = low;
    while (j < high)
    {
        if (stack[j] < pivot)
        {
            i++;
            swap(&stack[i], &stack[j]);
        }
        j++;
    }
    swap(&stack[i + 1], &stack[high]);
    return (i + 1);
}