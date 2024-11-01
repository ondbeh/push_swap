/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:19:05 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 15:25:21 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_list **stack_a, int print_flag)
{
	t_list	*new_last;
	t_list	*new_first;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	new_first = ft_lstlast(*stack_a);
	new_last = *stack_a;
	while (new_last->next != new_first)
		new_last = new_last->next;
	new_first->next = *stack_a;
	*stack_a = new_first;
	new_last->next = NULL;
	if (print_flag)
		ft_putendl_fd("rra\n", 1);
}

void rrb(t_list **stack_b, int print_flag)
{
	rra(stack_b, 0);
	if (print_flag)
		ft_putendl_fd("rrb\n", 1);
}

void rrr(t_list **stack_a, t_list **stack_b, int print_flag)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print_flag)
		ft_putendl_fd("rrr\n", 1);
}