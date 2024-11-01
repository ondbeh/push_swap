/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:06:34 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 15:17:27 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **stack_a, int print_flag)
{
	t_list	*last;
	t_list	*first;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)->next;
	last->next = first;
	first->next = NULL;
	if (print_flag)
		ft_putendl_fd("ra\n", 1);
}

void	rb(t_list **stack_b, int print_flag)
{
	ra(stack_b, 0);
	if (print_flag)
		ft_putendl_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b, int print_flag)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print_flag)
		ft_putendl_fd("rr\n", 1);
}
