/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:17:33 by rtournet          #+#    #+#             */
/*   Updated: 2021/06/26 11:08:36 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_point *print)
{
	print->width -= 1;
	if (print->minus == 1)
	{
		print->printlen += ft_putchar('%');
		while (print->width-- > 0)
			print->printlen += ft_putchar(' ');
	}
	else if (print->zero == 1)
	{
		while (print->width-- > 0)
			print->printlen += ft_putchar('0');
		print->printlen += ft_putchar('%');
	}
	else
	{
		while (print->width-- > 0)
			print->printlen += ft_putchar(' ');
		print->printlen += ft_putchar('%');
	}
}
