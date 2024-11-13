/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_solve_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:44:05 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/13 09:06:20 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_push(t_push *push, int index, int rot_left, int rot_right)
{
	push->index = index;
	push->rotations_left = rot_left;
	push->rotations_right = rot_right;
}

int	push_cost(t_push push)
{
	if (push.rotations_left >= 0 && push.rotations_right >= 0)
		return (max(push.rotations_left, push.rotations_right) + 1);
	if (push.rotations_left <= 0 && push.rotations_right <= 0)
		return (max(abs(push.rotations_left), abs(push.rotations_right)) + 1);
	else
		return (abs(push.rotations_left) + abs(push.rotations_right) + 1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	print_int(void *content)
{
	printf("%d\n", *(int *) content);
}
