/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:40:59 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/19 19:49:26 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack_node
{
    int	number;
    int index;
    int cost;
    int above_median;
    int cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *previous;
}               t_stack_node;

char* check_syntax_errors(char *argv);
char* duplicates(t_stack_node **a, long number);
char* free_errors(t_stack_node **a);
void free_stack(t_stack_node *stack);
void set_target_node_b(t_stack_node *a, t_stack_node *b);
void initialization_node_a(t_stack_node *a, t_stack_node *b);
void initialization_node_b(t_stack_node *a, t_stack_node *b);
void current_index(t_stack_node *stack);
void set_target_node_a(t_stack_node *a, t_stack_node *b);
void set_cost(t_stack_node *a, t_stack_node *b);
t_stack_node *set_cheapest(t_stack_node *stack);
char* initialization_of_stack_a(t_stack_node **a, char **argv);
int	ft_atol(const char *nptr);
void append_node(t_stack_node **stack, int n);
void preparation_for_push(t_stack_node **stack, t_stack_node *node, char stack_name);
void push(t_stack_node **a, t_stack_node **b);
void pa(t_stack_node **a, t_stack_node **b, bool print);
void pb(t_stack_node **a, t_stack_node **b, bool print);
void reverse_rotate(t_stack_node **stack);
void reverse_rotate_a(t_stack_node **a, bool print);
void reverse_rotate_b(t_stack_node **a, bool print);
void rrr(t_stack_node **a, t_stack_node **b, bool print);
void rotate_a(t_stack_node **a, bool print);
void rotate_b(t_stack_node **b, bool print);
void rr(t_stack_node **a, t_stack_node **b, bool print);
void sort_three(t_stack_node **a);
void turkish_algorithm(t_stack_node **a, t_stack_node **b);
void min_on_top(t_stack_node **a);
t_stack_node *find_min(t_stack_node *stack);
t_stack_node *find_last_node(t_stack_node *stack);
bool is_sorted(t_stack_node *stack);
void move_a_to_b(t_stack_node **a, t_stack_node **b);
void move_b_to_a(t_stack_node **a, t_stack_node **b);
void swap(t_stack_node **stack_head);
void swap_a(t_stack_node **a, bool print);
void swap_b(t_stack_node **b, bool print);
void ss(t_stack_node **a, t_stack_node **b, bool print);
int stack_size(t_stack_node *stack);
t_stack_node *find_max(t_stack_node *stack);
#endif