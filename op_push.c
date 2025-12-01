/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:14:45 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/01 17:49:44 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b, t_flag *flag)
{
	push(stack_b, stack_a);
	if (!flag->bench)
		ft_putstr_fd("pa\n", 1);
	flag->pa++;
}

void	do_pb(t_stack **stack_a, t_stack **stack_b, t_flag *flag)
{
	push(stack_a, stack_b);
	if (!flag->bench)
		ft_putstr_fd("pb\n", 1);
	flag->pb++;
}
