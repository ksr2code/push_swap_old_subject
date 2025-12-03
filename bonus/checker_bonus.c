/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:33:50 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/03 13:27:27 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_line(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
		do_sa_bon(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		do_sb_bon(stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		do_pa_bon(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb\n"))
		do_pb_bon(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		do_ra_bon(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		do_rb_bon(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		do_rr_bon(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		do_rra_bon(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		do_rrb_bon(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		do_rrr_bon(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line && *line)
	{
		if (!exec_line(line, stack_a, stack_b))
		{
			free(line);
			exit_error(stack_a, stack_b);
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	if (line)
		free(line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		s_size;

	if (ac < 2)
		return (0);
	if (!valid_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = get_stack_values(av);
	s_size = ft_stack_size(stack_a);
	set_index(stack_a, s_size);
	checker(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
