/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:30:45 by ksmailov          #+#    #+#             */
/*   Updated: 2025/12/01 21:31:46 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_numstr(const char *str)
{
	int	count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	count = ft_strlen(str);
	write(1, str, count);
	return (count);
}

static int	ft_print_strn(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		while (str[count] && count < flags.precision)
			write(1, &str[count++], 1);
	else
		while (str[count])
			write(1, &str[count++], 1);
	return (count);
}

int	ft_print_str(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (str == NULL && flags.precision < 6 && flags.precision >= 0)
		str = "";
	else if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && flags.precision > (int)ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		count += ft_print_strn(str, flags);
	if (flags.precision >= 0)
		count += ft_pad_width(flags.width, flags.precision, 0);
	else
		count += ft_pad_width(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		count += ft_print_strn(str, flags);
	return (count);
}
