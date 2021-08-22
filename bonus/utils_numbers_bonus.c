/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 06:07:53 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:26:04 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	int_len(long long n)
{
	int	i;

	i = 0;
	if (i < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	hexa_len(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long int	nb;
	long long int	len;

	nb = nbr;
	len = ft_strlen(base);
	if (nb < 0)
		nb *= -1;
	if (nb >= len)
		ft_putnbr_base(nb / len, base);
	ft_putchar(base[nb % len]);
}

void	ft_putnbr_unsigned(unsigned int nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (nbr >= (unsigned int)len)
		ft_putnbr_unsigned(nbr / (unsigned int)len, base);
	ft_putchar(base[nbr % (unsigned int)len]);
}

void	ft_putnbr_long_hexa(unsigned long long nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (nbr >= (unsigned long int)len)
		ft_putnbr_long_hexa(nbr / (unsigned long)len, base);
	ft_putchar(base[nbr % (unsigned long)len]);
}
