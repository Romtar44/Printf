/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <rtournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:36:09 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:24:23 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_struct(t_point *print)
{
	print->minus = -1;
	print->zero = -1;
	print->width = -1;
	print->precision = -1;
	print->p_init = -1;
	print->printlen = 0;
}

void	reset_struct(t_point *print)
{
	print->minus = -1;
	print->zero = -1;
	print->width = -1;
	print->precision = -1;
	print->p_init = -1;
}

int	parse_master(const char *str, t_point *print)
{
	int	i;

	i = 0;
	while ((str[i] == '0' || str[i] == '-') && str[i])
	{
		if (str[i] == '0')
			print->zero = 1;
		else if (str[i] == '-')
		{
			print->minus = 1;
			print->zero = -1;
		}
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
		i += width_value(str + i, print);
	if (str[i] == '.')
		i += precision_value(str + i, print);
	if (param_letter(*(str + i)))
		return (linker_master(str[i], print, i));
	else if (!param_letter(*(str + i)))
		return (1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	t_point	*print;
	int		i;

	i = 0;
	print = (t_point *)malloc(sizeof(t_point));
	if (!print)
		return (0);
	va_start(print->args, str);
	init_struct(print);
	while (*str)
	{
		reset_struct(print);
		if (*str == '%')
		{
			i = parse_master((str + 1), print);
			str += i;
		}
		else
			print->printlen += ft_putchar(*str);
		str++;
	}
	va_end(print->args);
	i = print->printlen;
	free(print);
	return (i);
}
