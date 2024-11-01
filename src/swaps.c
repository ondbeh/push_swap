/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:25:47 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 15:28:52 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(t_list **stack_a, int print_flag)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	third = second->next;
	*stack_a = second;
	second->next = first;
	first->next = third;
	if (print_flag)
		ft_putendl_fd("sa\n", 1);
}

void sb(t_list **stack_b, int print_flag)
{
	sa(stack_b, 0);
	if (print_flag)
		ft_putendl_fd("sb\n", 1);
}

void ss(t_list **stack_a, t_list **stack_b, int print_flag)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print_flag)
		ft_putendl_fd("ss\n", 1);
}
