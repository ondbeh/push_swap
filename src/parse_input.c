/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:39:21 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 17:45:35 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_duplicates(t_list *stack_a)
{
	t_list	*current;
	t_list	*runner;

	current = stack_a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (*(int *) current->content == *(int *) runner->content)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

static t_list	*allocate_new_node(int value)
{
	t_list	*node;
	int		*new_value;

	new_value = malloc(sizeof(int));
	if (!new_value)
		return (NULL);
	*new_value = value;
	node = ft_lstnew((int *) new_value);
	if (!node)
		free(new_value);
	return (node);
}

static t_list	*parse_argument(char *arg)
{
	t_list	*new_node;
	t_list	*head;
	long	value;
	char	*endptr;

	head = NULL;
	while (*arg)
	{
		if (!isdigit(*arg) && *arg != '-' && *arg != '+')
			return (ft_lstclear(&head, free), NULL);
		value = ft_strtol(arg, &endptr);
		if (arg == endptr || value < (long) INT_MIN || value > (long) INT_MAX)
			return (ft_lstclear(&head, free), NULL);
		new_node = allocate_new_node((int) value);
		if (!new_node)
			return (ft_lstclear(&head, free), NULL);
		ft_lstadd_back(&head, new_node);
		arg = endptr;
		if (!isspace(*arg))
			break ;
		++arg;
	}
	if (*arg)
		return (ft_lstclear(&head, free), NULL);
	return (head);
}

t_list	*parse_input(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*new_node;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = parse_argument(argv[i]);
		if (!new_node)
			error_handler("Error\n", &stack_a, NULL);
		ft_lstadd_back(&stack_a, new_node);
		++i;
	}
	if (check_duplicates(stack_a))
		error_handler("Error\n", &stack_a, NULL);
	return (stack_a);
}
