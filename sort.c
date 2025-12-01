/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:53:51 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/01 21:37:54 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **stack, t_flag *flag)
{
	int		highest;
	t_stack	*ptr;

	ptr = *stack;
	highest = ptr->index;
	while (ptr)
	{
		if (ptr->index > highest)
			highest = ptr->index;
		ptr = ptr->next;
	}
	if ((*stack)->index == highest)
		do_ra(stack, flag);
	else if ((*stack)->next->index == highest)
		do_rra(stack, flag);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack, flag);
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	int	min_index;
	int	r_count;
	int	rr_count;

	while (s_size > 3)
	{
		min_index = get_min_index(*stack_a);
		r_count = count_r(*stack_a, min_index + 1);
		rr_count = s_size - r_count;
		if (r_count <= rr_count)
			while ((*stack_a)->index != min_index)
				do_ra(stack_a, flag);
		else
			while ((*stack_a)->index != min_index)
				do_rra(stack_a, flag);
		if (is_sorted(*stack_a) && !(*stack_b))
			return ;
		do_pb(stack_a, stack_b, flag);
		s_size--;
	}
	tiny_sort(stack_a, flag);
	while (*stack_b)
		do_pa(stack_a, stack_b, flag);
}

static void	make_chunks(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	int	i;
	int	s_chunk;

	i = 0;
	s_chunk = ft_sqrt(s_size) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			do_pb(stack_a, stack_b, flag);
			if (*stack_a && ((*stack_a)->index <= i || (*stack_a)->index <= i
					+ s_chunk))
				do_rb(stack_b, flag);
			else
				do_rr(stack_a, stack_b, flag);
			i++;
		}
		else if ((*stack_a)->index <= i + s_chunk)
		{
			do_pb(stack_a, stack_b, flag);
			i++;
		}
		else
			do_ra(stack_a, flag);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	int	r_count;
	int	rr_count;

	make_chunks(stack_a, stack_b, s_size, flag);
	while (s_size - 1 >= 0)
	{
		r_count = count_r(*stack_b, s_size);
		rr_count = s_size - r_count;
		if (r_count <= rr_count)
		{
			while ((*stack_b)->index != s_size - 1)
				do_rb(stack_b, flag);
			do_pa(stack_a, stack_b, flag);
			s_size--;
		}
		else
		{
			while ((*stack_b)->index != s_size - 1)
				do_rrb(stack_b, flag);
			do_pa(stack_a, stack_b, flag);
			s_size--;
		}
	}
}
