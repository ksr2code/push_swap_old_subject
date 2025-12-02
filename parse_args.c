/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:50:47 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/01 18:05:03 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	have_duplicates(char **av)
{
	t_stack	*head;
	t_stack	*ptr1;
	t_stack	*ptr2;

	head = get_stack_values(av);
	if (!head)
		return (1);
	ptr1 = head;
	while (ptr1 && ptr1->next)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ptr1->value == ptr2->value)
			{
				free_stack(&head);
				return (1);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	free_stack(&head);
	return (0);
}

static int	valid_len(char *str, int start, int end)
{
	int	len;
	int	zeros;
	int	i;

	i = start;
	len = 0;
	zeros = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < end && str[i] == '0')
	{
		zeros++;
		len++;
		i++;
	}
	while (i < end && ft_isdigit(str[i]))
	{
		len++;
		i++;
	}
	if ((len - zeros) > 11)
		return (0);
	return (1);
}

int	check_num(char *str, int *i)
{
	int	start;

	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '\0')
		return (1);
	start = *i;
	if ((str[*i] == '-' || str[*i] == '+') && str[*i + 1] != '\0')
		(*i)++;
	if (!ft_isdigit(str[*i]))
		return (0);
	while (str[*i] == '0')
		(*i)++;
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (!valid_len(str, start, *i))
		return (0);
	if (str[*i] != '\0' && str[*i] != ' ')
		return (0);
	return (1);
}

int	valid_input(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
			if (!check_num(av[i], &j))
				return (0);
	}
	if (have_duplicates(av))
		return (0);
	return (1);
}
