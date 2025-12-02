/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:39:20 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/01 21:10:41 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_flag
{
	int				type;
	int				bench;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	float			disorder;
}					t_flag;

//============== parse =================
void				init_flags(t_flag *flag);
int					valid_input(char **av);
int					check_num(char *str, int *i);

//============== utils =================
void				exit_error(t_stack **stack_a, t_stack **stack_b);
void				free_stack(t_stack **stack);
int					is_sorted(t_stack *stack);
int					is_number(char *av);

//============== stack =================
t_stack				*get_stack_values(char **av);
void				set_index(t_stack *stack_a, int s_size);
long				ft_atol(const char *str);
t_stack				*stack_new(int nb);
int					ft_stack_size(t_stack *stack);
void				ft_stackadd_back(t_stack **stack, t_stack *new);

//============== sort ==================
void				chunk_sort(t_stack **stack_a, t_stack **stack_b, int s_size,
						t_flag *flag);
void				small_sort(t_stack **stack_a, t_stack **stack_b, int s_size,
						t_flag *flag);
void				tiny_sort(t_stack **stack, t_flag *flag);

//============ sort utils ==============
int					ft_sqrt(int nb);
int					get_min_index(t_stack *stack);
int					count_r(t_stack *stack, int s_size);

//=========== operations ==============
void				do_sa(t_stack **stack_a, t_flag *flag);
void				do_sb(t_stack **stack_b, t_flag *flag);
void				do_pa(t_stack **stack_a, t_stack **stack_b, t_flag *flag);
void				do_pb(t_stack **stack_a, t_stack **stack_b, t_flag *flag);
void				do_ra(t_stack **stack_a, t_flag *flag);
void				do_rb(t_stack **stack_b, t_flag *flag);
void				do_rr(t_stack **stack_a, t_stack **stack_b, t_flag *flag);
void				do_rra(t_stack **stack_a, t_flag *flag);
void				do_rrb(t_stack **stack_b, t_flag *flag);
void				do_rrr(t_stack **stack_a, t_stack **stack_b, t_flag *flag);

#endif
