/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:57:06 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/01 21:03:20 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	long	i;

	i = 0;
	if (nb < 1)
		return (0);
	while (i * i < (long)nb)
		i++;
	if (i * i == (long)nb)
		return (i);
	return ((int)i - 1);
}

int	get_min_index(t_stack *stack)
{
	int	min_index;

	if (!stack)
		return (-1);
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

int	count_r(t_stack *stack, int s_size)
{
	int	count;

	count = 0;
	while (stack && stack->index != (s_size - 1))
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
