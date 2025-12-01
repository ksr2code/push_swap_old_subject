/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:56:05 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/01 17:56:06 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack_a, int s_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--s_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = s_size;
	}
}

static void	import_num(char *str, t_stack **stack_a)
{
	int		i;
	t_stack	*tmp;
	long	nb;

	i = 0;
	while (str[i])
	{
		if (is_number(&str[i]))
		{
			nb = ft_atol(&str[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				exit_error(stack_a, NULL);
			tmp = stack_new((int)nb);
			if (!tmp)
				exit_error(stack_a, NULL);
			ft_stackadd_back(stack_a, tmp);
			while (is_number(&str[i]))
				i++;
		}
		else
			i++;
	}
}

t_stack	*get_stack_values(char **av, t_flag flag)
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	if (flag.type)
		i++;
	if (flag.bench)
		i++;
	stack_a = NULL;
	while (av[i])
	{
		import_num(av[i], &stack_a);
		i++;
	}
	return (stack_a);
}
