/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:51:46 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 17:45:54 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include "libft/libft.h"

typedef struct s_push
{
	int	index;
	int	rotations_left;
	int	rotations_right;
}	t_push;

typedef enum e_push_type
{
	ROT_BOTH,
	REV_ROT_BOTH,
	ROT_A_REV_ROT_B,
	REV_ROT_A_ROT_B
}	t_push_type;

void	error_handler(char *error_message, t_list **stack_a, t_list **stack_b);
t_list	*parse_input(int argc, char **argv);
void	sa(t_list **stack_a, int print_flag);
void	sb(t_list **stack_b, int print_flag);
void	ss(t_list **stack_a, t_list **stack_b, int print_flag);
void	pa(t_list **stack_a, t_list **stack_b, int print_flag);
void	pb(t_list **stack_a, t_list **stack_b, int print_flag);
void	ra(t_list **stack_a, int print_flag);
void	rb(t_list **stack_b, int print_flag);
void	rr(t_list **stack_a, t_list **stack_b, int print_flag);
void	rra(t_list **stack_a, int print_flag);
void	rrb(t_list **stack_b, int print_flag);
void	rrr(t_list **stack_a, t_list **stack_b, int print_flag);
void	solve_push_swap(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack);
void	small_sort(t_list **stack_a);
void	big_sort(t_list **stack_a, t_list **stack_b);
void	assign_push(t_push *push, int index, int rot_left, int rot_right);
int		push_cost(t_push push);
int		max(int a, int b);
int		abs(int a);
int		get_exact_index(const int value, t_list *stack);
int		get_desc_index(const int value, t_list *stack);
int		get_asc_index(const int value, t_list *stack);
int		get_push_type(t_push push);
void	perform_push(t_push push, t_list **stack_a, t_list **stack_b);
t_push	find_cheapest_push(t_list *stack_a, t_list *stack_b);
void	push_back_to_a(t_list **stack_a, t_list **stack_b);

// Debug functions

void	print_int(void *content);

#endif
