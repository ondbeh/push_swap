/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:01:14 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/08 11:02:16 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int ch)
{
	if (ch < 32 || ch > 126)
		return (0);
	return (1);
}
