/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:16:08 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:23:48 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_char(t_point *print)
{
	char	c;

	c = va_arg(print->args, int);
	print->width -= 1;
	if (print->minus == 1)
	{
		print->printlen += ft_putchar(c);
		while (print->width-- > 0)
			print->printlen += ft_putchar(' ');
	}
	else if (print->width > 0)
	{
		while (print->width-- > 0)
			print->printlen += ft_putchar(' ');
		print->printlen += ft_putchar(c);
	}
	else
		print->printlen += ft_putchar(c);
}
