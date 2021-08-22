/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 01:12:29 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:24:58 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_integer_precision(t_point *print, long long n)
{
	if (n < 0 && print->minus == 1)
		print->printlen += ft_putchar('-');
	while (print->precision-- > 0)
		print->printlen += ft_putchar('0');
}

void	print_integer_width(t_point *print, long long n)
{
	if (print->precision > -1)
		print->zero = -1;
	if (print->width && print->zero == 1)
	{
		if (n < 0 && print->minus == -1)
			print->printlen += ft_putchar('-');
		while (print->width-- > 0)
			print->printlen += ft_putchar('0');
	}
	else
	{
		while (print->width-- > 0)
			print->printlen += ft_putchar(' ');
		if (n < 0 && print->minus == -1)
			print->printlen += ft_putchar('-');
	}
}

void	integer_flag(t_point *print, long long n)
{
	int	j;

	j = int_len(n);
	if (print->p_init == 1)
		print->zero = -1;
	if (j >= print->precision && print->p_init == 1)
		print->precision = 0;
	else
		print->precision -= j;
	if (n < 0)
		j++;
	if (print->width > 0 && print->p_init == 1)
		print->width = print->width - (print->precision + j);
	else if (print->width > 0 && print->p_init == -1)
		print->width -= j;
}

void	print_integer(t_point *print)
{
	long long	n;

	n = (long long)va_arg(print->args, int);
	if (print->precision == 0 && n == 0)
		return (print_integer_width(print, n));
	integer_flag(print, n);
	if (print->minus == -1)
	{
		print_integer_width(print, n);
		print_integer_precision(print, n);
		ft_putnbr_base(n, "0123456789");
	}
	else if (print->minus == 1)
	{
		print_integer_precision(print, n);
		ft_putnbr_base(n, "0123456789");
		print_integer_width(print, n);
	}
	print->printlen += int_len(n);
}
