/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 05:48:48 by rtournet          #+#    #+#             */
/*   Updated: 2021/07/03 06:56:55 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned_precision(t_point *print)
{
	while (print->precision-- > 0)
		print->printlen += ft_putchar('0');
}

void	print_unsigned_width(t_point *print)
{
	if (print->precision > -1)
		print->zero = -1;
	if (print->width && print->zero == 1)
	{
		while (print->width-- > 0)
			print->printlen += ft_putchar('0');
	}
	else
	{
		while (print->width-- > 0)
			print->printlen += ft_putchar(' ');
	}
}

void	unsigned_flag(t_point *print, unsigned int n)
{
	int	j;

	j = int_len(n);
	if (print->p_init == 1)
		print->zero = -1;
	if (j >= print->precision && print->p_init == 1)
		print->precision = 0;
	else
		print->precision -= j;
	if (print->width > 0 && print->p_init == 1)
		print->width = print->width - (print->precision + j);
	else if (print->width > 0 && print->p_init == -1)
		print->width -= j;
}

void	print_unsigned(t_point *print)
{
	unsigned int	n;

	n = va_arg(print->args, unsigned int);
	if (print->precision == 0 && n == 0)
		return (print_unsigned_width(print));
	unsigned_flag(print, n);
	if (print->minus == -1)
	{
		print_unsigned_width(print);
		print_unsigned_precision(print);
		ft_putnbr_unsigned(n, "0123456789");
	}
	else if (print->minus == 1)
	{
		print_unsigned_precision(print);
		ft_putnbr_unsigned(n, "0123456789");
		print_unsigned_width(print);
	}
	print->printlen += int_len(n);
}
