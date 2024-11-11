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
void	push_back_to_a(t_list **stack_a, t_list **stack_b);

#endif
