/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:58:58 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/13 12:16:02 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	index;

	if (!*stack_b)
		return ;
	index = get_asc_index(*(int *)(*stack_b)->content, *stack_a);
	if (index != 0 && index > ft_lstsize(*stack_a) / 2)
	{
		while (index++ < ft_lstsize(*stack_a))
			rra(stack_a, 1);
	}
	else
	{
		while (index-- > 0)
			ra(stack_a, 1);
	}
	pa(stack_a, stack_b, 1);
	push_back_to_a(stack_a, stack_b);
}
