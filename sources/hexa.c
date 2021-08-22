/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:17:20 by rtournet          #+#    #+#             */
/*   Updated: 2021/07/03 06:54:55 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa_precision(t_point *print)
{
	while (print->precision-- > 0)
		print->printlen += ft_putchar('0');
}

void	print_hexa_width(t_point *print)
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

void	hexa_flag(t_point *print, unsigned int n)
{
	int	j;

	j = hexa_len(n);
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

void	print_hexa(t_point *print, char *str)
{
	unsigned int	n;

	n = (unsigned int)va_arg(print->args, int);
	if (print->precision == 0 && n == 0)
		return (print_hexa_width(print));
	hexa_flag(print, n);
	if (print->minus == -1)
	{
		print_hexa_width(print);
		print_hexa_precision(print);
		ft_putnbr_unsigned(n, str);
	}
	else if (print->minus == 1)
	{
		print_hexa_precision(print);
		ft_putnbr_unsigned(n, str);
		print_hexa_width(print);
	}
	print->printlen += hexa_len(n);
}
