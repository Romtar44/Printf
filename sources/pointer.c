/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:16:52 by rtournet          #+#    #+#             */
/*   Updated: 2021/07/03 06:55:25 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width_pointer(t_point *print)
{
	while (print->width-- > 0)
		print->printlen += ft_putchar(' ');
}

void	print_cancer(t_point *print)
{
	print->width -= 6;
	if (print->minus == -1)
	{
		print_width_pointer(print);
		ft_putnstr("(null)", 6, print);
	}
	else if (print->minus == 1)
	{
		ft_putnstr("(null)", 6, print);
		print_width_pointer(print);
	}
}

void	print_pointer(t_point *print)
{
	unsigned long int	p;

	p = va_arg(print->args, unsigned long int);
	if (!p)
	{
		print_cancer(print);
		return ;
	}
	print->width -= (hexa_len(p) + 2);
	if (print->minus == 1)
	{
		ft_putnstr("0x", 2, print);
		ft_putnbr_long_hexa(p, BASE_M);
		print_width_pointer(print);
	}
	else if (print->minus == -1)
	{
		print_width_pointer(print);
		ft_putnstr("0x", 2, print);
		ft_putnbr_long_hexa(p, BASE_M);
	}
	print->printlen += hexa_len(p);
}
