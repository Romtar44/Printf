/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:38:54 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:24:10 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_value(const char *str, t_point *print)
{
	int	i;

	i = 0;
	print->width = 0;
	if (str[i] == '*')
	{
		print->width = va_arg(print->args, int);
		if (print->width < 0)
		{
			print->width *= -1;
			print->zero = -1;
			print->minus = 1;
		}
		i++;
	}
	else
		while (ft_isdigit(str[i]))
			print->width = (print->width * 10) + (str[i++] - 48);
	return (i);
}

int	precision_value(const char *str, t_point *print)
{
	int	i;

	i = 0;
	if (str[i++] == '.')
	{
		print->precision = 0;
		print->p_init = 1;
		if (str[i] == '*')
		{
			print->precision = va_arg(print->args, int);
			if (print->precision < 0)
			{
				print->precision = -1;
				print->p_init = -1;
			}
			i++;
		}
		else
			while (ft_isdigit(str[i]))
				print->precision = (print->precision * 10) + (str[i++] - 48);
	}
	return (i);
}
