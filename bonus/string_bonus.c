/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:16:43 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:25:41 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_width_string(t_point *print, char *str)
{
	if (print->p_init == 1 && print->width > -1)
	{
		if (print->precision < ft_strlen(str))
			print->width -= print->precision;
		else
			print->width -= ft_strlen(str);
	}
	else if (print->p_init == -1 && print->width > -1)
		print->width -= ft_strlen(str);
	while (print->width-- > 0)
		print->printlen += ft_putchar(' ');
}

void	print_string(t_point *print)
{
	char	*str;

	str = (char *)va_arg(print->args, char *);
	if (!str)
		str = "(null)";
	if (print->minus == 1)
	{
		if (print->precision > -1)
			ft_putnstr(str, print->precision, print);
		else
			ft_putnstr(str, ft_strlen(str), print);
		print_width_string(print, str);
	}
	else if (print->minus == -1)
	{
		print_width_string(print, str);
		if (print->precision > -1)
			ft_putnstr(str, print->precision, print);
		else
			ft_putnstr(str, ft_strlen(str), print);
	}
}
