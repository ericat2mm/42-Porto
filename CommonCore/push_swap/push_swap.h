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
    int lowest;
    int highest;
}   tack;

//algorithm
void push_a(tack *lista);
void push_b(tack *lista);
void    rotate_a(tack *lista);
void    rotate_b(tack *lista);
void    rotate_ab(tack *lista);
void    reverse_rotate_a(tack *lista);
void    reverse_rotate_b(tack *lista);
void    reverse_rotate_ab(tack *lista);
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
void  define_sort(tack *lista);
void  sort_three(tack *lista);
void sort_four(tack *lista);
void sort_five(tack *lista);
void sort_big(tack *lista);

//Print Function
void   print_list_stack_a(tack *lista);
void print_list_stack_b(tack *lista);


//Utils Functions
int find_min_index(tack *lista);
void turkish_algorithm_to_b(tack *lista);
void turkish_algorithm_to_a(tack *lista);
int get_lowest(tack *lista);
int get_highest(tack *lista);
int distance(int end, int start);
void sort_list(tack *lista, int target);
#endif