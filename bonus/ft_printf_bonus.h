/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <rtournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:35:10 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/07 17:23:34 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

# define BASEM "0123456789ABCDEF"
# define BASE_M "0123456789abcdef"

typedef struct s_point
{
	va_list	args;
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		p_init;
	int		printlen;	
}				t_point;

/* 
 * UTILITAIRE
 * */

int		ft_strlen(char *str);
int		ft_isdigit(char c);
int		ft_putchar(char c);
void	ft_putnstr(char *str, int n, t_point *print);
void	ft_putnbr_base(int nbr, char *base);
int		int_len(long long n);
void	ft_putnbr_unsigned(unsigned int nbr, char *base);
int		hexa_len(unsigned long int n);
void	ft_putnbr_long_hexa(unsigned long long int nbr, char *base);

/*
 *GESTION DES FLAGS ET DU LINKAGE
 * */

int		param_letter(char c);

int		width_value(const char *str, t_point *print);
int		precision_value(const char *str, t_point *print);

int		parse_master(const char *str, t_point *print);
int		linker_master(char c, t_point *print, int i);

int		ft_printf(const char *str, ...);

/*
 *GESTION DES SPECIFIERS
 * */

void	print_char(t_point *print);

void	print_percent(t_point *print);

/*
 *GESTION DES INT
 * */

void	print_integer(t_point *print);
void	print_integer_precision(t_point *print, long long n);
void	print_integer_width(t_point *print, long long n);
void	integer_flag(t_point *print, long long n);

/*
 * GESTION DES CHAINES DE CARACTERES
 * */

void	print_string(t_point *print);
void	print_width_string(t_point *print, char *str);

/*
 *GESTION DES HEXA
 */

void	print_hexa(t_point *print, char *str);
void	print_hexa_precision(t_point *print);
void	print_hexa_width(t_point *print);
void	hexa_flag(t_point *print, unsigned int n);

/*
 * GESTION DES UNSIGNED
 * */

void	print_unsigned(t_point *print);
void	print_unsigned_precision(t_point *print);
void	print_unsigned_width(t_point *print);
void	unsigned_flag(t_point *print, unsigned int n);

/*
 * GESTION DES POINTEURS
 * */

void	print_pointer(t_point *print);
void	print_width_pointer(t_point *print);

/*
 * INITIALISATION ET REINITIALISATION DE LA STRUCTURE
 * */

void	reset_struct(t_point *print);
void	init_struct(t_point *print);

#endif
