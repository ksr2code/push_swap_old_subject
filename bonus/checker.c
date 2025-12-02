#include "checker.h"

char *ft_read_line(void)
{

}

static void	checker(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	char *line;

	line = ft_read_line();
	while (line && *line)
	{

	}
	if (is_sorted(*stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
