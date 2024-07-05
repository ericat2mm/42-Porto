/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:30:44 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/28 03:04:09 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_stack
{
	long int		val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//ALGORITHM UTILS
int				stacksize(t_stack **stack);
bool			sorted(t_stack **stack);
long			get_bigest(t_stack **stack);
long			get_lowest(t_stack **stack);
int				get_position(t_stack **stack, int target);

//ALGORITHM
void			sort_three(t_stack **stack);
void			sort_five(t_stack **stack_a, t_stack **stack_b);
void			big_sort(t_stack **stack_a, t_stack **stack_b);
void			sort_until_three(t_stack **stack_a, t_stack **stack_b);
void			back_to_a(t_stack **stack_a, t_stack **stack_b);

//BIG_SORT_UTIlS
int				get_tar_val_b(t_stack **stack_b, int current);
long			get_tar_val_a(t_stack **stack_a, int current);
int				get_cheapest(t_stack **stack_a, t_stack **stack_b);
int				get_total(t_stack **stack_a, t_stack **stack_b, int val);
int				targetdist(t_stack **stack, int val);

//INSERT_STACKS
struct s_stack	*create(char *nums);
struct s_stack	insert_to_stacks(struct s_stack **head, char **nums);
void			insert_to_last(struct s_stack *head, char *nums);
void			free_stack(t_stack *stack);

//PUSH SWAP
void			push_swap(t_stack **stack_a, t_stack **stack_b);
int				ft_atol(const char *str);
int				get_cheapest_to_final(t_stack **stack_a);

//PUSH
void			push(t_stack **stack_sender, t_stack **stack_receiver, char c);

//REVERSE_ROTATE
void			reverse_rotate(t_stack **stack, char leters);
void			reverse_rot_both(t_stack **stack_a, t_stack **stack_b, char l);

//ROTATE
void			rotate(t_stack **stack, char leters);
void			rotate_both(t_stack **stack_a, t_stack **stack_b, char l);

//SWAP
void			swap(t_stack **stack);
void			swap_both(t_stack **stack_a, t_stack **stack_b, char l);
void			swap_a(t_stack **stack_a);
void			swap_b(t_stack **stack_b);

//VERIFY ARGS
bool			process_args(int argc, char **argv, t_stack **stack_a);
int				verify_numbers(char **args);
int				verify_max(char **args);
int				verify_dupl(char **args);
int				verify_args(char **args);
#endif
