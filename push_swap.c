/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:51:06 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/01 21:54:25 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	if (is_sorted(*stack_a))
		return ;
	else if (s_size == 2)
		do_sa(stack_a, flag);
	else if (s_size == 3)
		tiny_sort(stack_a, flag);
	else if (s_size <= 10)
		small_sort(stack_a, stack_b, s_size, flag);
	else
		chunk_sort(stack_a, stack_b, s_size, flag);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		s_size;
	t_flag	flag;

	if (ac < 2)
		return (0);
	init_flags(&flag);
	if (!valid_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = get_stack_values(av);
	s_size = ft_stack_size(stack_a);
	set_index(stack_a, s_size);
	push_swap(&stack_a, &stack_b, s_size, &flag);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
