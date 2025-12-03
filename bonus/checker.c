#include "checker.h"

int exec_line(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa"))
		do_sa(stack_a);
	else if (!ft_strcmp(line, "sb"))
		do_sb(stack_b);
	else if (!ft_strcmp(line, "pa"))
		do_pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb"))
		do_pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra"))
		do_ra(stack_a);
	else if (!ft_strcmp(line, "rb"))
		do_rb(stack_b);
	else if (!ft_strcmp(line, "rr"))
		do_rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra"))
		do_rra(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		do_rrb(stack_b);
	else if (!ft_strcmp(line, "rrr"))
		do_rrr(stack_a, stack_b);
	else 
		return (0);
	return (1);
}

static void	checker(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	char *line;

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
		free (line);
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
	checker(&stack_a, &stack_b, s_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
