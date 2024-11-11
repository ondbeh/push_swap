/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:44 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 17:57:58 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_current_index(int value, t_list *stack)
{
	int		index;
	t_list	*current;
	t_list	*last;

	index = 0;
	current = stack;
	last = ft_lstlast(stack);
	if (ft_lstsize(stack) < 2)
		return (0);
	while (current->next)
	{
		if (*(int *)current->content == value || )
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

int	find_cheapest_push(t_list *stack_a, t_list *stack_b)
{
	int		cheapest_push_index;
	int		cheapest_push_cost;
	int		current_push_cost;
	t_list	*current;

	cheapest_push_cost = INT_MAX;
	current = stack_a;
	while (current)
	{
		current_push_cost = 0;
		current_push_cost = get_push_cost(current->content, stack_a, stack_b);
		if (current_push_cost < cheapest_push_cost)
		{
			cheapest_push_cost = current_push_cost;
			cheapest_push_index = get_current_index(*((int *) current->content), stack_a);
		}
		current = current->next;
	}
	return (cheapest_push_index);
}


void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	cheapest_push_index;

	if (ft_lstsize(*stack_a) <= 3)
	{
		small_sort(stack_a);
		return ;
	}
	cheapest_push_index = find_cheapest_push(*stack_a, *stack_b);
	perform_cheapest_push(cheapest_push_index, stack_a, stack_b);
	big_sort(stack_a, stack_b);
}