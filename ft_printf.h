/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:52:44 by mwiecek           #+#    #+#             */
/*   Updated: 2024/04/07 21:03:03 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_helper(int n);
int	ft_putstr(char *s);
//static int	ft_print_ptr_chars(unsigned long n);
int	ft_print_ptr(unsigned long ptr);
int	ft_put_cap_x(unsigned int n);
int	ft_put_x(unsigned int n);
int	ft_put_un_nbr(unsigned int n);
//static int	what_char(char c, va_list arg);
int	ft_printf(const char *s, ...);

#endif
