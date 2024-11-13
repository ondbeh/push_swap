/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:12:37 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/13 10:44:57 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_exact_index(const int value, t_list *stack)
{
	int		index;
	t_list	*current;

	index = 0;
	current = stack;
	if (ft_lstsize(stack) < 2)
		return (0);
	while (current)
	{
		if (*(int *)current->content == value)
			return (index);
		++index;
		current = current->next;
	}
	return (0);
}

int	get_desc_index(const int value, t_list *stack)
{
	int		index;
	int		curr_value;
	int		next_value;

	index = 1;
	if (ft_lstsize(stack) < 2)
		return (0);
	while (stack->next)
	{
		curr_value = *(int *)stack->content;
		next_value = *(int *)stack->next->content;
		if ((value < curr_value && value > next_value)
			|| (curr_value < next_value
				&& (value < curr_value || value > next_value)))
			return (index);
		++index;
		stack = stack->next;
	}
	return (0);
}

int	get_asc_index(const int value, t_list *stack)
{
	int		index;
	int		curr_value;
	int		next_value;

	index = 1;
	if (ft_lstsize(stack) < 2)
		return (0);
	while (stack->next)
	{
		curr_value = *(int *)stack->content;
		next_value = *(int *)stack->next->content;
		if ((value > curr_value && value < next_value)
			|| (curr_value > next_value
				&& (value > curr_value || value < next_value)))
			return (index);
		++index;
		stack = stack->next;
	}
	return (0);
}
