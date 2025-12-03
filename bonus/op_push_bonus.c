/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:14:45 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/03 13:27:37 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	do_pa_bon(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}

void	do_pb_bon(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}
