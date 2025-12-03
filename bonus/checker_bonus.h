/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:34:47 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/03 13:27:34 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include "../push_swap.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

void	do_pa_bon(t_stack **stack_a, t_stack **stack_b);
void	do_pb_bon(t_stack **stack_a, t_stack **stack_b);
void	do_rra_bon(t_stack **stack_a);
void	do_rrb_bon(t_stack **stack_b);
void	do_rrr_bon(t_stack **stack_a, t_stack **stack_b);
void	do_ra_bon(t_stack **stack_a);
void	do_rb_bon(t_stack **stack_b);
void	do_rr_bon(t_stack **stack_a, t_stack **stack_b);
void	do_sa_bon(t_stack **stack_a);
void	do_sb_bon(t_stack **stack_b);

#endif
