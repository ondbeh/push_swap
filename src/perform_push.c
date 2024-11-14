/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:40:16 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/14 17:28:28 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	perform_rr(t_push push, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < push.rotations_left && i < push.rotations_right)
	{
		rr(stack_a, stack_b, 1);
		++i;
	}
	while (i < push.rotations_left)
	{
		ra(stack_a, 1);
		++i;
	}
	while (i < push.rotations_right)
	{
		rb(stack_b, 1);
		++i;
	}
}

static void	perform_rrr(t_push push, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < abs(push.rotations_left) && i < abs(push.rotations_right))
	{
		rrr(stack_a, stack_b, 1);
		++i;
	}
	while (i < abs(push.rotations_left))
	{
		rra(stack_a, 1);
		++i;
	}
	while (i < abs(push.rotations_right))
	{
		rrb(stack_b, 1);
		++i;
	}
}

static void	perform_ra_rrb(t_push push, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < push.rotations_left)
	{
		ra(stack_a, 1);
		++i;
	}
	i = 0;
	while (i < abs(push.rotations_right))
	{
		rrb(stack_b, 1);
		++i;
	}
}

static void	perform_rra_rb(t_push push, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < abs(push.rotations_left))
	{
		rra(stack_a, 1);
		++i;
	}
	i = 0;
	while (i < push.rotations_right)
	{
		rb(stack_b, 1);
		++i;
	}
}

void	perform_push(t_push push, t_list **stack_a, t_list **stack_b)
{
	t_push_type	push_type;

	push_type = get_push_type(push);
	if (push_type == ROT_BOTH)
		perform_rr(push, stack_a, stack_b);
	else if (push_type == REV_ROT_BOTH)
		perform_rrr(push, stack_a, stack_b);
	else if (push_type == ROT_A_REV_ROT_B)
		perform_ra_rrb(push, stack_a, stack_b);
	else if (push_type == REV_ROT_A_ROT_B)
		perform_rra_rb(push, stack_a, stack_b);
	pb(stack_a, stack_b, 1);
}
