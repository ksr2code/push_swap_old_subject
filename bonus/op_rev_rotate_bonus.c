/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:14:50 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/03 13:26:43 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prev = *stack;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	do_rra_bon(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	do_rrb_bon(t_stack **stack_b)
{
	rev_rotate(stack_b);
}

void	do_rrr_bon(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
