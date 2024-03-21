/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:11:30 by emedeiro          #+#    #+#             */
/*   Updated: 2024/03/17 18:38:46 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft_modified/libft.h"
#include <stddef.h>
#include <limits.h>

typedef struct stack
{
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;
    int *array;
}   tack;

//algorithm
void push_a(int *stack_a, int *stack_b);
void push_b(int *stack_a, int *stack_b);
void    rotate_a(int *stack_a, int size_a);
void    rotate_b(int *stack_b, int size_b);
void    rotate_ab(int *stack_a, int size_a, int *stack_b, int size_b);
void    reverse_rotate_a(int *stack_a, int size_a);
void    reverse_rotate_b(int *stack_b, int size_b);
void    reverse_rotate_ab(int *stack_a, int size_a, int *stack_b, int size_b);
void    swap(int *argv1, int *argv2);
void    swap_a(int *sa);
void    swap_b(int *sb);
void    swap_ab(int *sa, int *sb);

//Stack with two arguments
int    two_argcs_logic(char **argv);
int    two_argcs_verification(char **temporary);
tack   *creation_of_stacks_two_argcs(char **temporary);

//Stack with more than two arguments
int    more_argcs_logic(int argc, char **argv);
int    more_argcs_verification(char **argv);
tack   *creation_of_stacks_more_argcs(int argc, char **argv);

//Both
int    doubles_verification(char **argv);
int    ft_strcmp(const char *s1, const char *s2);
void   ft_putnbr(int n);
int   is_sorted(int size_a, int *stack_a);

//Sort Functions
void  define_sort(int *stack_a, int size_a, int *stack_b, int size_b);
void  sort_three(int *stack_a);
void sort_four(int *stack_a, int *stack_b, int size_a);
void sort_five(int *stack_a, int *stack_b, int size_a);
void sort_big(int *stack_a, int *stack_b, int size_a, int size_b);

//Print Function
void   print_list_stack_a(int *lista, int size);

//Utils Functions
int find_min_index(int *stack_a, int size_a);
void rotate_to_top(int *stack_a, int size_a, int min_index);
int is_empty(int size_a, int size_b);
void sort_array(int *stack_a, int size_a);
void create_chunk(int *stack_a, int size_a, int *stack_b, int chunk_size);
void quick_sort(int *stack, int size);
int partition(int *stack, int low, int high);
void quick_sort_recursive(int *stack, int low, int high);
#endif