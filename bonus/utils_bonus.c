/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:41:19 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:25:54 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isdigit(char c)
{
	return (c <= '9' && c >= '0');
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	param_letter(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnstr(char *str, int n, t_point *print)
{
	if (!str)
		return ;
	while (*str && n-- > 0)
	{
		write(1, str++, 1);
		print->printlen++;
	}
}
