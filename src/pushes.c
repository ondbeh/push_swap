/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:33:30 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 16:02:40 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int print_flag)
{
	t_list	*new_first_a;

	if (!*stack_b)
		return ;
	new_first_a = *stack_b;
	*stack_b = (*stack_b)->next;
	new_first_a->next = *stack_a;
	*stack_a = new_first_a;
	if (print_flag)
		ft_putendl_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b, int print_flag)
{
	if (!*stack_a)
		return ;
	pa(stack_b, stack_a, 0);
	if (print_flag)
		ft_putendl_fd("pb\n", 1);
}
