/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:06:35 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 10:15:39 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_handler(char *error_message, t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	ft_putstr_fd(error_message, 2);
	exit(1);
}
