/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:13:04 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/13 10:13:04 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_cheapest_push(t_push cheapest_push, t_list **stack_a, t_list **stack_b)
{
	if (cheapest_push.rotations_left >= 0 && cheapest_push.rotations_right >= 0)
	{
		while (cheapest_push.rotations_left--)
			ra(stack_a, 1);
		while (cheapest_push.rotations_right--)
			rb(stack_b, 1);
	}
	else if (cheapest_push.rotations_left <= 0 && cheapest_push.rotations_right <= 0)
	{
		while (cheapest_push.rotations_left++)
			rra(stack_a, 1);
		while (cheapest_push.rotations_right++)
			rrb(stack_b, 1);
	}
	else if (cheapest_push.rotations_right >= 0)
	{
		while (cheapest_push.rotations_left++)
			rra(stack_a, 1);
		while (cheapest_push.rotations_right--)
			rb(stack_b, 1);
	}
	else
	{
		while (cheapest_push.rotations_left--)
			ra(stack_a, 1);
		while (cheapest_push.rotations_right++)
			rrb(stack_b, 1);
	}
	pb(stack_a, stack_b, 1);
}

t_push	get_push(const int value, t_list *stack_a, t_list *stack_b)
{
	t_push	current_push;
	t_push	cheapest_push;
	int		index_left;
	int		index_right;

	index_left = get_exact_index(value, stack_a);
	index_right = get_desc_index(value, stack_b);
	//printf("value: %d index_left: %d index_right: %d\n", value, index_left, index_right);
	assign_push(&cheapest_push, index_left, index_left, index_right);
	assign_push(&current_push, index_left,
		index_left - ft_lstsize(stack_a), index_right - ft_lstsize(stack_b));
	if (push_cost(current_push) < push_cost(cheapest_push))
		cheapest_push = current_push;
	assign_push(&current_push, index_left, index_left,
		index_right - ft_lstsize(stack_b));
	if (push_cost(current_push) < push_cost(cheapest_push))
		cheapest_push = current_push;
	assign_push(&current_push, index_left,
		index_left - ft_lstsize(stack_a), index_right);
	if (push_cost(current_push) < push_cost(cheapest_push))
		cheapest_push = current_push;
	return (cheapest_push);
}

t_push	find_cheapest_push(t_list *stack_a, t_list *stack_b)
{
	t_push	cheapest_push;
	t_push	current_push;
	t_list	*current;

	assign_push(&cheapest_push, -1, INT_MAX / 2, INT_MAX / 2);
	current = stack_a;
	while (current)
	{
		current_push = get_push(*(int *)current->content, stack_a, stack_b);
		if (push_cost(current_push) < push_cost(cheapest_push))
			cheapest_push = current_push;
		// printf("current_push: index:%d rot_left:%d rot_right:%d\n",
		// 	current_push.index, current_push.rotations_left, current_push.rotations_right);
		// printf("cheapest_push: index:%d rot_left:%d rot_right:%d\n",
		// 	cheapest_push.index, cheapest_push.rotations_left, cheapest_push.rotations_right);
		current = current->next;
	}
	return (cheapest_push);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_push	cheapest_push;

	if (ft_lstsize(*stack_a) <= 3)
	{
		small_sort(stack_a);
		return ;
	}
	cheapest_push = find_cheapest_push(*stack_a, *stack_b);
	printf("total cheapest_push: index:%d rot_left:%d rot_right:%d\n",
		cheapest_push.index, cheapest_push.rotations_left, cheapest_push.rotations_right);
	perform_cheapest_push(cheapest_push, stack_a, stack_b);
	big_sort(stack_a, stack_b);
}
