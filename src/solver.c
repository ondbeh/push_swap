/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:32:40 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 16:57:18 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_sorted_asc(t_list *stack)
{
	t_list	*current;
	int		counter;

	if (!stack || ft_lstsize(stack) < 3)
		return (1);
	current = stack;
	counter = 0;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			++counter;
		current = current->next;
	}
	if (*(int *)current->content > *(int *)stack->content)
		++counter;
	return (counter < 2);
}

static void	rotate_to_start(t_list **stack_a)
{
	int	index;

	index = get_asc_index(INT_MIN, *stack_a);
	if (index > ft_lstsize(*stack_a) / 2)
	{
		while (index++ < ft_lstsize(*stack_a))
			rra(stack_a, 1);
	}
	else
	{
		while (index-- > 0)
			ra(stack_a, 1);
	}
}

void	small_sort(t_list **stack_a)
{
	if (is_sorted_asc(*stack_a))
		return ;
	sa(stack_a, 1);
}

void	solve_push_swap(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (is_sorted_asc(*stack_a))
		;
	else if (ft_lstsize(*stack_a) <= 3)
		small_sort(stack_a);
	else
	{
		pb(stack_a, stack_b, 1);
		pb(stack_a, stack_b, 1);
		big_sort(stack_a, stack_b);
		push_back_to_a(stack_a, stack_b);
	}
	rotate_to_start(stack_a);
}
