/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 04:19:45 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:25:09 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	linker_master(char c, t_point *print, int i)
{
	if (c == 'c')
		print_char(print);
	if (c == '%')
		print_percent(print);
	if (c == 'd' || c == 'i')
		print_integer(print);
	if (c == 's')
		print_string(print);
	if (c == 'p')
		print_pointer(print);
	if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			print_hexa(print, BASE_M);
		if (c == 'X')
			print_hexa(print, BASEM);
	}
	if (c == 'u')
		print_unsigned(print);
	i++;
	return (i);
}
