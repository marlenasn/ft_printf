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

static int    ft_putchar(char c);
static int    ft_putnbr(int n);
static int    ft_putstr(char *s);
static int    ft_print_ptr(unsigned long ptr, int first);
static int    ft_put_X(unsigned int n);
static int    ft_put_x(unsigned int n);
static int    ft_put_un_nbr(unsigned int n);
static int	what_char(char c, va_list arg);
int	ft_printf(const char *s, ...);



#endif
